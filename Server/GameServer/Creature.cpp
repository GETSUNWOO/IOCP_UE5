#include "pch.h"
#include "Creature.h"

Creature::Creature()
{
	objectInfo->set_object_type(Protocol::ObjectType_TYPE_CREATURE);
}

Creature::~Creature()
{
}
