
#include "World.h"
#include "stdio.h"
#include "Dlist.h"
Player::Player(const char* names, const char*des, Room* loc, uint life, uint damages, uint cash, ObjectType ty) :Creature(names, des, loc, life, damages, ty), money(cash)
{
	maxcap = 3;
	maxeq = 2;
	elementsinv = 0;
	elementseq = 0;
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
		if (world->entities[i]->type == EXIT)
		{
			if (((Exit*)world->entities[i])->direction == dire)
			{
				if (world->ThePlayer->location->name == ((Exit*)world->entities[i])->origin->name)
				{
					//printf("\n\n You can see: %s \n", ((Exit*)world->entities[i])->destination->name);
					printf("\n\n  %s \n\n", ((Exit*)world->entities[i])->description);
					//printf("\n\n You can see: %s \n\n", ((Exit*)world->entities[i]))->destination->name));
				}
			}
		}
	}
}
void Player::Open()const
{
	for (uint i = 0; i < 40; i++)
	{
		if (world->entities[i]->type == EXIT)
		{
			if (((Exit*)world->entities[i])->hasDoor == true)
			{
				if (((Exit*)world->entities[i])->open == true)
				{
					if (world->ThePlayer->location->name == ((Exit*)world->entities[i])->origin->name || world->ThePlayer->location->name == ((Exit*)world->entities[i])->destination->name)
					{
						((Exit*)world->entities[i])->open = false;
						if (world->ThePlayer->location->name == ((Exit*)world->entities[i])->origin->name)
						{
							printf("\nThe Door has opened\n");
						}
					}
					
				}
			}
		}
	}
}
void Player::Close()const
{
	for (uint i = 0; i < 40; i++)
	{
		if (world->entities[i]->type == EXIT)
		{
			if (((Exit*)world->entities[i])->hasDoor == true)
			{
				if (((Exit*)world->entities[i])->open == false)
				{
					if (world->ThePlayer->location->name == ((Exit*)world->entities[i])->origin->name || world->ThePlayer->location->name == ((Exit*)world->entities[i])->destination->name)
					{
						((Exit*)world->entities[i])->open = true;
						if (world->ThePlayer->location->name == ((Exit*)world->entities[i])->origin->name)
						{
							printf("\nThe Door has closed\n");
						}
					}
				}
			}
		}
	}
}
void Player::buy(Vector<MyString>& item)
{
	if (world->ThePlayer->location == world->TheSeller->location)
	{
		//printf("You have %i dollars", world->ThePlayer->money);
		Dnode<Entity*>* temp1 = world->TheSeller->SList.first;
		for (; temp1 != nullptr; temp1 = temp1->next)
		{

			for (uint i = 34; i < 39; i++)
			{
				// temp1 = world->TheSeller->SList.first;

				if (item[1] == ((Item*)world->entities[i])->name)
				{
					if (((Item*)world->entities[i])->name == temp1->data->name)

					{
						if (world->ThePlayer->money >= ((Item*)temp1->data)->price)
						{
							if (world->ThePlayer->elementsinv < maxcap)
							{
								printf("\n You've bought the %s\n\n", ((Item*)temp1->data)->name);
								((Item*)world->entities[i])->inventory = true;
								((Item*)world->entities[i])->location = world->ThePlayer->location;
								world->TheSeller->SList.erase(temp1);
								world->ThePlayer->money -= ((Item*)world->entities[i])->price;
								elementsinv++;
								return;
								;

							}

						}

					}

				}


			}
		}
	}
}
void Player::use(Vector<MyString>& item)
{
	if (((Item*)world->entities[36])->inventory == true)
	{
		if (world->ThePlayer->location == ((Room*)world->entities[10]) || world->ThePlayer->location == ((Room*)world->entities[11]))
		{
			printf("\nYou used the ticket and traveled by train!\n ");
			if (world->ThePlayer->location == ((Room*)world->entities[10]))
			{
				world->ThePlayer->location = ((Room*)world->entities[11]);
				return;
			}
			else if (world->ThePlayer->location == ((Room*)world->entities[11]))
			{
				world->ThePlayer->location = ((Room*)world->entities[10]);
				return;
			}
		}
	}
}
void Player::attack()
{
	if (world->ThePlayer->location == world->TheKiller->location)
	{
		if (world->TheKiller->life > 0)
		{
			attacking = true;
			world->TheKiller->life -= world->ThePlayer->damage;
			printf("\nYou attacked the killer and now he is at %i of life\n", world->TheKiller->life);
		}
		else
		{
			printf("\n You've killed the Killer!!!!!\n\n");
		}
		
	}
}
void Player::sell(Vector<MyString>& item)
{
	if (world->ThePlayer->location == world->TheSeller->location)
	{
		printf("\nYou have %i dollars\n", world->ThePlayer->money);
		for (uint i = 34; i < 39; i++)
		{
			if (((Item*)world->entities[i])->name == item[1])
			{
				if (((Item*)world->entities[i])->inventory == true)
				{
					((Item*)world->entities[i])->inventory = false;
					world->TheSeller->SList.push_back(((Item*)world->entities[i]));
					world->ThePlayer->money += ((Item*)world->entities[i])->price;
					printf("\n You've sold the %s\n Now you have %i\n\n", ((Item*)world->entities[i])->name,world->ThePlayer->money);
					return;
				}
			}
		}
		/*Dnode<Entity*>* temp1 = world->TheSeller->SList.first;
		for (; temp1 != nullptr; temp1 = temp1->next)
		{

			for (uint i = 34; i < 39; i++)
			{
				// temp1 = world->TheSeller->SList.first;

				if (item[1] == ((Item*)world->entities[i])->name)
				{
					if (((Item*)world->entities[i])->name == temp1->data->name)

					{
						if (world->ThePlayer->money >= ((Item*)temp1->data)->price)
						{
							if (world->ThePlayer->elementsinv < maxcap)
							{
								printf("\n You've sold the %s\n\n", ((Item*)temp1->data)->name);
								((Item*)world->entities[i])->inventory = true;
								((Item*)world->entities[i])->location = world->ThePlayer->location;
								elementsinv++;
								break;
								;

							}

						}

					}

				}


			}
		}*/
	}
}


void Player::Pick(Vector<MyString>& item)
{
	for (uint i = 34; i < 39; i++)
	{
		if (item[1] == ((Item*)world->entities[i])->name)
		{
			if (((Item*)world->entities[i])->location == world->ThePlayer->location)
			{
				if (((Item*)world->entities[i])->inventory == false)
				{
					if (elementsinv < maxcap)
					{
						if ((item[1] == "bag"))
						{
							maxcap = maxcap + 2;
							if (((Item*)world->entities[i])->InBox == true);
							((Item*)world->entities[i])->inventory = true;
						}
						printf("\n\nyou've picked the %s!\n\n", ((Item*)world->entities[i])->name);
						((Item*)world->entities[i])->inventory = true;
						((Item*)world->entities[i])->location = world->ThePlayer->location;
						elementsinv++;
					}
					else
					{
						printf("\n\nthere is no room in your pockets!\n\n");
					}
					
				}
			}
		}
	}
}
void Player::Drop(Vector<MyString>& item)
{
	for (uint i = 34; i < 39; i++)
	{
		if (item[1] == ((Item*)world->entities[i])->name)
		{
		
				if (((Item*)world->entities[i])->inventory == true)
				{
					if ((item[1] == "bag"))
					{
						maxcap = maxcap - 2;
					}
					printf("\n\nyou've dropped the %s!\n\n", ((Item*)world->entities[i])->name);
					((Item*)world->entities[i])->inventory = false;
					((Item*)world->entities[i])->equip = false;
					((Item*)world->entities[i])->location = world->ThePlayer->location;
					elementsinv--;
				}
			}
		}
	
}
void Player::Equip(Vector<MyString>& item)
{
	for (uint i = 34; i < 39; i++)
	{
		if (item[1] == ((Item*)world->entities[i])->name)
		{
			if (((Item*)world->entities[i])->inventory == true)
			{
				if (((Item*)world->entities[i])->equip == false)
				{

					if (elementseq < maxeq)
					{
						printf("\n\nYou've equipped the %s!\n\n", ((Item*)world->entities[i])->name);
						((Item*)world->entities[i])->equip = true;
						elementseq++;
						if (((Item*)world->entities[i])->name == "knife")
						{
							world->ThePlayer->damage += 30;
						}
						if (((Item*)world->entities[i])->name == "crowbar")
						{
							world->ThePlayer->damage += 10;
						}
						if (((Item*)world->entities[i])->name == "flashlight")
						{
							for (uint i = 0; i < 22; i++)
							{
								if (((Room*)world->entities[i])->lightopen== false)
								{
									((Room*)world->entities[i])->lightopen = true;
								}
							}
						}
					}
				}
			}
		}
	}
}
void Player::Unequip(Vector<MyString>& item)
{
	for (uint i = 34; i < 39; i++)
	{
		if (item[1] == ((Item*)world->entities[i])->name)
		{
			if (((Item*)world->entities[i])->inventory == true)
			{
				if (((Item*)world->entities[i])->equip == true)
				{
					printf("\n\nYou've unequipped the %s!\n\n", ((Item*)world->entities[i])->name);
					((Item*)world->entities[i])->equip = false;
					elementseq--;
					if (((Item*)world->entities[i])->name == "knife")
					{
						world->ThePlayer->damage -= 30;
					}
					if (((Item*)world->entities[i])->name == "crowbar")
					{
						world->ThePlayer->damage -= 10;
					}
					if (((Item*)world->entities[i])->name == "flashlight")
					{
						for (uint i = 0; i < 22; i++)
						{
							if (((Room*)world->entities[i])->light == true)
							{
								if (((Room*)world->entities[i])->lightopen == true)
								{
									((Room*)world->entities[i])->lightopen =false;
								}
							}
						}
					}
				}
			}
		}
	}
}
void Player::Put(Vector<MyString>& item)
{
	if (world->ThePlayer->location == ((Item*)world->entities[38])->location || ((Item*)world->entities[38])->inventory==true)
	{
		for (uint i = 34; i < 39; i++)
		{
			if (item[1] == ((Item*)world->entities[i])->name)
			{
				if (((Item*)world->entities[i])->inventory == true)
				{
					if (((Item*)world->entities[i])->InBox == false)
					{
						((Item*)world->entities[i])->InBox = true;
						if (((Item*)world->entities[38])->inventory == false)
						{
							((Item*)world->entities[i])->inventory = false;
							printf("\nyou've put %s into the bag\n", ((Item*)world->entities[i])->name);
							elementseq--;
							return;
						}
						printf("\nyou've put %s into the bag\n", ((Item*)world->entities[i])->name);
						return;
					}
				}
			}
		}
	}

}
void Player::Get(Vector<MyString>& item)
{
	if (world->ThePlayer->location == ((Item*)world->entities[38])->location || ((Item*)world->entities[38])->inventory == true)
	{
		for (uint i = 34; i < 39; i++)
		{
			if (item[1] == ((Item*)world->entities[i])->name)
			{
				if (((Item*)world->entities[i])->InBox == true)
				{
					if (((Item*)world->entities[38])->inventory == false)
					{
						((Item*)world->entities[i])->inventory = true;
						elementseq++;
					}
					((Item*)world->entities[i])->InBox = false;
					printf("you've got the  %s from bag\n", ((Item*)world->entities[i])->name);
				}
			}
		}
	}
}