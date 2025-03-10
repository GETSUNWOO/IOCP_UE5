// Fill out your copyright notice in the Description page of Project Settings.


#include "S1GameInstance.h"
#include "Sockets.h"
#include "Common/TcpSocketBuilder.h"
#include "Serialization/ArrayWriter.h"
#include "SocketSubsystem.h"
#include "PacketSession.h"
#include "Protocol.pb.h"
#include "ClientPacketHandler.h"
#include "S1MyPlayer.h"


void US1GameInstance::ConnectToGameServer()
{
	//���� ����� (stream -> TCP ���)
	Socket = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateSocket(TEXT("Stream"), TEXT("Client Socket"));
	
	// �ּ� ���ε�(���� �پ���ϴ� ������ �ּҸ� ����)
	FIPv4Address Ip;
	FIPv4Address::Parse(IpAddress, Ip);

	//Internetaddr -> �پ���� ���� �ּ�
	TSharedRef<FInternetAddr> InternetAddr = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();
	InternetAddr->SetIp(Ip.Value);
	InternetAddr->SetPort(Port);

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Connecting To Server...")));

	//���� -> connect�� ���ŷ ����̴�(�������)
	bool Connected = Socket->Connect(*InternetAddr);

	if (Connected)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Connection Success")));

		// Session
		GameServerSession = MakeShared<PacketSession>(Socket);
		GameServerSession->Run();

		// TEMP : Lobby ���� �ɸ��� ����â ��
		{
			Protocol::C_LOGIN Pkt;
			SendBufferRef SendBuffer = ClientPacketHandler::MakeSendBuffer(Pkt);
			SendPacket(SendBuffer);
		}
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Connection Failed")));
	}
}

void US1GameInstance::DisconnectFromGameServer()
{
	if (Socket == nullptr || GameServerSession == nullptr)
		return;

	Protocol::C_LEAVE_GAME LeavePkt;
	SEND_PACKET(LeavePkt);

	/*if (Socket) // recv send �������ε� �̷��� �翬�� ����
	{
		ISocketSubsystem* SocketSubsystem = ISocketSubsystem::Get();
		SocketSubsystem->DestroySocket(Socket);
		Socket = nullptr;
	}*/
}

void US1GameInstance::HandleRecvPackets()
{
	if (Socket == nullptr || GameServerSession == nullptr)
		return;

	GameServerSession->HandleRecvPackets();
}

void US1GameInstance::SendPacket(SendBufferRef SendBuffer)
{
	if (Socket == nullptr || GameServerSession == nullptr)
		return;

	GameServerSession->SendPacket(SendBuffer);
}

void US1GameInstance::HandleSpawn(const Protocol::ObjectInfo& ObjectInfo, bool IsMine)
{
	if (Socket == nullptr && GameServerSession == nullptr)
		return;

	auto* World = GetWorld();

	// �ߺ�ó�� üũ
	const uint64 ObjectId = ObjectInfo.object_id();
	if (Players.Find(ObjectId) != nullptr) // TMap�� null üũ�� �������
		return;

	FVector SpawnLocation(ObjectInfo.pos_info().x(), ObjectInfo.pos_info().y(), ObjectInfo.pos_info().z());

	if (IsMine)
	{
		auto* PC = UGameplayStatics::GetPlayerController(this,0);
		AS1Player* Player = Cast<AS1Player>(PC->GetPawn());
		if (Player == nullptr)
			return;

		Player->SetPosInfo(ObjectInfo.pos_info());
		MyPlayer = Player;
		Players.Add(ObjectInfo.object_id(), Player);
	}
	else
	{
		AS1Player* Player = Cast<AS1Player>(World->SpawnActor(OtherPlayerClass, &SpawnLocation));
		Player->SetPosInfo(ObjectInfo.pos_info());
		Players.Add(ObjectInfo.object_id(), Player);
	}
}

void US1GameInstance::HandleSpawn(const Protocol::S_ENTER_GAME& EnterGamePkt)
{
	HandleSpawn(EnterGamePkt.player(), true);
}

void US1GameInstance::HandleSpawn(const Protocol::S_SPAWN& SpawnPkt)
{
	for (auto& Player : SpawnPkt.players())
	{
		HandleSpawn(Player, false);
	}
}

void US1GameInstance::HandleDespawn(uint64 ObjectId)
{
	if (Socket == nullptr || GameServerSession == nullptr)
		return;

	auto* World = GetWorld();
	if (World == nullptr)
		return;

	//TODO : DESPAWN

	AS1Player** FindPlayer = Players.Find(ObjectId);
	if (FindPlayer == nullptr)
		return;

	World->DestroyActor(*FindPlayer);
}

void US1GameInstance::HandleDespawn(const Protocol::S_DESPAWN& DespawnPkt)
{
	for (auto& ObjectId : DespawnPkt.object_ids())
	{
		HandleDespawn(ObjectId);
	}
}

void US1GameInstance::HandleMove(const Protocol::S_MOVE& MovePkt)
{
	if (Socket == nullptr || GameServerSession == nullptr)
		return;

	auto* World = GetWorld();
	if (World == nullptr)
		return;

	const uint64 ObjectId = MovePkt.info().object_id();
	AS1Player** FindPlayer = Players.Find(ObjectId);
	if (FindPlayer == nullptr)
		return;

	AS1Player* Player = (*FindPlayer);
	if (Player->IsMyPlayer())
		return;

	const Protocol::PosInfo& Info = MovePkt.info();

	//Player->SetPosInfo(Info);
	Player->SetDestInfo(Info);
}
