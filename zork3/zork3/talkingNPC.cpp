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
		if ((world->temporal) == "talk vendor" || (world->temporal) == "talk vendor 1" || (world->temporal) == "talk vendor 2")
		{
			if ((world->temporal) == "talk vendor")
			{
				Talk();
			}
		respond();
		}
		else
		{
			Tstate = MOVING;
		}
		
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
	printf("\nYou hear a firendly music somwhere at  %s\n", ((Room*)world->entities[i])->name);
	if (world->ThePlayer->location == world->talker->location)
	{
		Tstate = TALKING;
	}
}
void talkingNPC::Talk()
{
	if (world->words.size() != 0)
	{
		if (world->ThePlayer->location == world->talker->location)
		{
			printf("\n\nWhat do you want?\nWhat shall you respond\n1)Hi\n2)Bye\n");
			//respond();
		}
		else
		{
			Tstate = MOVING;
		}
	}
}
void talkingNPC::respond()
{
	if (world->temporal == "talk vendor 1")
	{
		printf("\nBeep! It's a lovely day isn't it\n");
		Talk();
	}
	if (world->temporal == "talk vendor 2")
	{
		printf("\nBye! Have a nice trip in CandyLand!\n");
		world->temporal = "\0";
		Tstate = MOVING;
	}
}
	

