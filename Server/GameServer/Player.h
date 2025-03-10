#pragma once
#include "Creature.h"

/*-----------------------
		Player
------------------------*/

class GameSession;
class Room;

class Player : public Creature
{
public:
	Player();
	virtual ~Player();

public:
	weak_ptr<GameSession> session;
};

