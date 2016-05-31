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
		if ((world->temporal) == "talk robot" || (world->temporal) == "talk robot 1" || (world->temporal) == "talk robot 2")
		{
			if ((world->temporal) == "talk robot")
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
	
	}
}
void talkingNPC::Move()
{
	int i = (rand() % 2);
	world->talker->location = ((Room*)world->entities[i]);
	//printf("\nYou hear a firendly music somwhere at  %s\n", ((Room*)world->entities[i])->name);
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
			printf("\n\nWhat do you want?\nWhat shall you answer\n1)Hi\n2)Bye\n");
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
	if (world->temporal == "talk robot 1")
	{
		if (world->ThePlayer->money == 0)
		{
			printf("\nBeep! It's a lovely day isn't it. Looks like you need some money\n");
			world->ThePlayer->money += 50;
			printf("The robot gave you 50 dollars!!!\n");
			Talk();
		}
		else
		{
			printf("\nBeep! It's a lovely day isn't it.\n");
			Talk();
		}
	}
	if (world->temporal == "talk robot 2")
	{
		printf("\nBye! Have a nice trip in CandyLand!\n");
		world->temporal = "\0";
		Tstate = MOVING;
	}
}
	

