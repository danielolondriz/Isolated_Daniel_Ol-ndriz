#include "World.h"

talkingNPC::talkingNPC(const char* names, const char*des, Room* loc, uint li, uint dam, ObjectType ty) :Creature(names, des, loc, li,dam, ty)
{}
talkingNPC::~talkingNPC()
{}

void talkingNPC::Update()
{
	switch (Tstate)
	{
	case MOVING:
		break;
	case TALKING:
		break;
	case DEAD:
		break;
	case DISAPPEAR:
		break;
	}
}