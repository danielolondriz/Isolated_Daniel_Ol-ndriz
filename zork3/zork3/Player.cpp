
#include "World.h"
#include "stdio.h"
Player::Player(const char* names, const char*des, Room* loc, uint life, ObjectType ty) :Creature(names,des, loc, life,ty)
{

}
Player::~Player(){};

void Player::Go(const dir dire)const
{
	for (uint i = 0; i < 40; i++)
	{
		if (world->entities[i]->type == EXIT)
		{
			if (((Exit*)world->entities[i])->direction == dire)
			{
				//printf("You are now at: %s\n", ((Exit*)world->entities[i])->origin->name);
			
				if (world->ThePlayer->location->name == ((Exit*)world->entities[i])->origin->name)
				{
					world->ThePlayer->location = ((Exit*)world->entities[i])->destination;
					//
					printf("You are now at: %s\n", world->ThePlayer->location->name);
				}
			}
		}
	}
}