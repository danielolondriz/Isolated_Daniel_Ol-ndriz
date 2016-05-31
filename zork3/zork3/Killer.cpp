#include "World.h"


Killer::Killer(const char* names, const char*des, Room* loc, int li, uint dam, ObjectType ty) :Creature(names, des, loc, li, dam, ty)
{}
Killer::~Killer()
{}

void Killer::Update()
{
	switch (Killstate)
	{
	case IDLE:

		if (world->ThePlayer->location == world->TheKiller->location)
		{
			Killstate = FIGHT;
			
		}
		break;
		
	case FIGHT:
		Fight();
		break;
	case DEAD:
		
		break;

	}
}
void Killer::Fight()
{
	if (world->TheKiller->life > 0)
	{
		if (world->ThePlayer->life > 0)
		{
			world->ThePlayer->life -= world->TheKiller->damage;
			if (world->ThePlayer->life >= 10)
			{
				printf("\nThe killer attacked you and now you are at %i of life\n", world->ThePlayer->life);
			}
			else
			{
				printf("\nThe killer attacked you and now you are at 0 of life\n", world->ThePlayer->life);
			}

			
		}
		
	}
	else
	{
		Killstate = DEAD;
	}
}