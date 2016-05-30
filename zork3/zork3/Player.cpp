
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
					if (((Exit*)world->entities[i])->destination->lightopen == false)
					{
						printf("\nIt's too dark to get in\n");
						return ;
					}
					if (((Exit*)world->entities[i])->open == true)
					{
						printf("\nDoor is colsed\n");
						return ;
					}
					world->ThePlayer->location = ((Exit*)world->entities[i])->destination;
					//
					printf("You are now at: %s\n", world->ThePlayer->location->name);
					return ;
				}
			}
		}
	}
	printf("there is a wall");
}
void Player::look(const dir dire)const
{

	for (uint i = 0; i < 40; i++)
	{
	}
}