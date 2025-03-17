// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "S1.h"
#include "S1GameInstance.generated.h"
class AS1Player;
class AS1SpawnPoint;
/**
 * 
 */
UENUM(BlueprintType)
enum class EPlayerType : uint8 
{
	PLAYER_TYPE_NONE = 0 UMETA(DisplayName = "None"),
	PLAYER_TYPE_ARCHER = 1 UMETA(DisplayName = "Archer"),
	PLAYER_TYPE_GUNNER = 2 UMETA(DisplayName = "Gunner"),
	PLAYER_TYPE_MAGE = 3 UMETA(DisplayName = "Sorcerer")
};

UCLASS()
class S1_API US1GameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void ConnectToGameServer();

	UFUNCTION(BlueprintCallable)
	void DisconnectFromGameServer();

	UFUNCTION(BlueprintCallable)
	void HandleRecvPackets();

	void SendPacket(SendBufferRef SendBuffer);

public:

	void HandleSpawn(const Protocol::ObjectInfo& PlayerInfo, const Protocol::PlayerType PlayerType ,bool IsMine);
	void HandleSpawn(const Protocol::S_ENTER_GAME& EnterGamePkt);
	void HandleSpawn(const Protocol::S_SPAWN& SpawnPkt, const Protocol::PlayerType PlayerType);

	void HandleDespawn(uint64 ObjectId);
	void HandleDespawn(const Protocol::S_DESPAWN& DespawnPkt);

	void HandleMove(const Protocol::S_MOVE& MovePkt);

public:
	// GameServer
	class FSocket* Socket;
	FString IpAddress = TEXT("127.0.0.1");
	int16 Port = 7777;
	TSharedPtr<class PacketSession> GameServerSession;

public:
	UPROPERTY(EditAnywhere)
	TSubclassOf<AS1Player> OtherPlayerClass;

	AS1Player* MyPlayer;
	TMap<uint64, AS1Player*> Players;

	UPROPERTY(BlueprintReadWrite)
	EPlayerType _PlayerType;

};
