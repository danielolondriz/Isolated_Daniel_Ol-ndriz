#include "World.h"
#include <time.h>
#include<Windows.h>
talkingNPC::talkingNPC(const char* names, const char*des, Room* loc, uint li, uint dam, ObjectType ty) :Creature(names, des, loc, li,dam, ty)
{}
talkingNPC::~talkingNPC()
{}

void talkingNPC::Update()
{
	switch (Tstate)
	{
	case MOVING:
		Move();
		break;
	case TALKING:
		break;
	case DEAD:
		break;
	case DISAPPEAR:
		break;
	}
}
void talkingNPC::Move()
{
	int i = (rand() % 2);
	world->talker->location = ((Room*)world->entities[i]);
	printf("I am at %s", ((Room*)world->entities[i])->name);
	if (world->ThePlayer->location == world->talker->location)
	{
		Tstate = TALKING;
	}
}