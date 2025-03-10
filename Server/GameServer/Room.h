#pragma once
#include "JobQueue.h"

/*-----------------------
		Room
------------------------*/

class Room : public JobQueue
{
public:
	Room();
	virtual ~Room();
	
public:
	bool EnterRoom(ObjectRef object);
	bool LeaveRoom(ObjectRef object);

	bool HandleEnterPlayer(PlayerRef player);
	bool HandleLeavePlayer(PlayerRef player);

	void HandleMove(Protocol::C_MOVE pkt);

public:
	void UpdateTick();

	RoomRef GetRoomRef();

private:
	bool AddObject(ObjectRef object);
	bool RemoveObject(uint64 objectId);

	USE_LOCK;

private:

	void Broadcast(SendBufferRef sendBuffer, uint64 exceptId = 0);


private:
	unordered_map<uint64, ObjectRef> _objects;
};

extern RoomRef GRoom;