#include "World.h"
#include<stdio.h>
#include<stdlib.h>
#include "conio.h"
//#include "MyString.h"
#include <Windows.h>
#define MAX_ITEMS 5
#define MAX_INVENTORY 3
#define MAX_EQUIPPED 2
#define MAX_BOX 2
//KBHIT
#define DELAY 5000
#define COMMANDBUFFER 50

World::World(){
	CreateWorld();
}
void World::CreateWorld()
{
	//ROOMS
	//room 0
	entities.Push_back ( new Room("Entrance Plaza", "This is the Entrance Plaza of the park. A rusty statue stands in the middle.\n In the North there is the main street.\n And in the west you can see a Train Station", false, true, ROOM));
	//room 1
	entities.Push_back(new Room("Main Street", "This is the glorious Main Street. On your left you can see a dark haunted house. On your right a Shop, and in front of you the street continues.", false, true,ROOM));
	//room 2
	entities.Push_back(new Room("Haunted House", "It's such a dark place, that noone would like to be in.", true, false,ROOM));
	//room 3
	entities.Push_back(new Room("Shop", "The Shop looks quite abandoned. On one side you can see a selling machine.", false, true,ROOM));
	//room 4
	entities.Push_back(new Room("End of the Street", "Looks like the Main street ends here. You can either go left to  the Ferris Wheel, or go down to your right, where a dark looking underground passage is located.", false, true,ROOM));
	//room 5
	entities.Push_back(new Room("Ferris Wheel", "You stand in front of the rusted old Ferris Wheel. it doesn't seem to work", false, true,ROOM));
	//room 6
	entities.Push_back(new Room("Underground Passage", "Between all the rubish you can see light coming from the north", true, false,ROOM));
	//room 7
	entities.Push_back(new Room("Fountain Plaza", "A big Plaza stands in front of you. An abandoned Roller coaster can be seen on your right, a Dock far in the North. Another building can be seen on your left with the name north train Station on it.", false, true,ROOM));
	//room 8
	entities.Push_back(new Room("Roller Coaster", "Since the power is off, the old looking Roller coaster wont work.\n", false, true,ROOM));
	//room 9
	entities.Push_back(new Room("Dock", "A Boat stands in front of you but, it's cabin is locked with a keychain.\n", false, true,ROOM));
	//room 10
	entities.Push_back(new Room("South Train Station, you can se a seller", "This is the south train station. There is a train, but it doesn't seem to work.\n", false, true,ROOM));
	//room 11
	entities.Push_back(new Room("North Train Station", "This is the magestic North train station. Yet no train seems to be coming...\n", false, true,ROOM));
	
	//EXITS
	//exit 0
	entities.Push_back(new Exit((Room*)entities[0], (Room*)entities[10], west,false, false, "Train Station", "you see the Train station",EXIT));
	//exit 1
	entities.Push_back(new Exit((Room*)entities[1],(Room*)entities[4], north, false, false, "End of street", "you see theEnd of street", EXIT));
	//exit 2
	entities.Push_back(new Exit((Room*)entities[1], (Room*)entities[0], south, false, false, "Entrance Plaza", "you see the Entrance Plaza", EXIT));
	//exit 3
	entities.Push_back(new Exit((Room*)entities[1], (Room*)entities[3], east, true, true, "Shop", "you see the Shop", EXIT));
	//exit 4
	entities.Push_back(new Exit((Room*)entities[1], (Room*)entities[2], west, false, false, "haunted House", "you see the haunted House", EXIT));
	//exit 5
	entities.Push_back(new Exit((Room*)entities[4], (Room*)entities[5], west, false, false, "FerrisWheels", "you see the FerrisWheels", EXIT));
	//exit 6
	entities.Push_back(new Exit((Room*)entities[4], (Room*)entities[6], east, false, false, "Underground", "you see the Underground", EXIT));
	//exit 7
	entities.Push_back(new Exit((Room*)entities[4], (Room*)entities[1], south, false, false, "main street", "you see the Main street", EXIT));
	//exit 8
	entities.Push_back(new Exit((Room*)entities[5],(Room*)entities[4], east, false, false, "End of street", "you see the End of street", EXIT));
	//exit 9
	entities.Push_back(new Exit((Room*)entities[6], (Room*)entities[7], north, false, false, "Fountain Plaza", "you see the Fountain Plaza", EXIT));
	//exit 10
	entities.Push_back(new Exit((Room*)entities[6],(Room*)entities[4], west, false, false, "End of street", "you see the End of street", EXIT));
	//exit 11
	entities.Push_back(new Exit((Room*)entities[7], (Room*)entities[6], south, false, false, "Underground", "you see the Underground Passage", EXIT));
	//exit 12
	entities.Push_back(new Exit((Room*)entities[7], (Room*)entities[9], north, false, false, "Dock", "you see the Dock", EXIT));
	//exit 13
	entities.Push_back(new Exit((Room*)entities[7], (Room*)entities[8], east, false, false, "Roller Coaster", "you see the Roller Coaster", EXIT));
	//exit 14
	entities.Push_back(new Exit((Room*)entities[7], (Room*)entities[11], west, false, false, "North Train Station", "you see the North Train Station", EXIT));
	//exit 15
	entities.Push_back(new Exit((Room*)entities[11], (Room*)entities[7], east, false, false, "Fountain Plaza", "you see the Fountain Plaza", EXIT));
	//exit 16
	entities.Push_back(new Exit((Room*)entities[8], (Room*)entities[7], west, false, false, "Fountain Plaza", "you see the Fountain Plaza", EXIT));
	//exit 17
	entities.Push_back(new Exit((Room*)entities[9], (Room*)entities[7], south, false, false, "Fountain Plaza", "you see the Fountain Plaza", EXIT));
	//exit 18
	entities.Push_back(new Exit((Room*)entities[0], (Room*)entities[1], north, false, false, "main street", "you see the Main street", EXIT));
	//exit 19
	entities.Push_back(new Exit((Room*)entities[10], (Room*)entities[0], east, false, false, "Entrance Plaza", "you see the Entrance Plaza", EXIT));
	//exit 20
	entities.Push_back(new Exit((Room*)entities[3], (Room*)entities[1], west, true, true, "main street", "you see the Main street", EXIT));
	//exit 21
	entities.Push_back(new Exit((Room*)entities[2], (Room*)entities[1], east, false, false, "main street", "you see the Main street", EXIT));

	//ITEMS
	//item 0
	entities.Push_back(new Item("flashlight", "This is a flashlight", (Room*)entities[3], false, false, false, false, ITEM,10));
	//item 1
	entities.Push_back(new Item("crowbar", "This is a crowbar", (Room*)entities[5], false, false, false, false, ITEM,20));
	//item 2
	entities.Push_back(new Item("ticket", "This is a Train Ticket", (Room*)entities[10], false, false, false, false, ITEM,50));
	//item 3
	entities.Push_back(new Item("knife", "This is a Knife", (Room*)entities[10], false, false, false, false, ITEM,50));
	//item 4
	entities.Push_back(new Item("bag", "This is a bag", (Room*)entities[2], false, false, true, false, ITEM,10));
	
	//CREATURES
	//NPC
	entities.Push_back(new talkingNPC("Walking robot", "Walking security Robot ", (Room*)entities[1], 100,0, CREATURE));
	//player
	entities.Push_back(new Player("Player", "Player", (Room*)entities[0], 100,20,0, CREATURE));
	//sellerNPC
	entities.Push_back(new SellerNPC("Seller", "This is a vendor", (Room*)entities[10], 100, 20, CREATURE));
	//Killer
	entities.Push_back(new Killer("Killer", "This is the Killer", (Room*)entities[0
	], 100,30, CREATURE));

	talker = (talkingNPC*)entities[39];
	ThePlayer = (Player*)entities[40];
	TheSeller = (SellerNPC*)entities[41];
	TheKiller = (Killer*)entities[42];
}
void World::printItems()
{
	for (uint i = 34; i < 39; i++)
	{
		if (((Item*)entities[i])->location == ThePlayer->location)
		{
			if (((Item*)entities[i])->inventory == false)
			{
				printf("In this room there is a %s\n\n", ((Item*)entities[i])->name);
			}
			
		}
	}
}
void World::printShop()
{
	if (ThePlayer->location == TheSeller->location)
	{
		printf("Hello, I'm the seller of this park!\n You better don't drop anything on the floor, as I will be cleaning the station!\nWhat do you want to buy\n");
		Dnode<Entity*>* temp1 = world->TheSeller->SList.first;
		for (uint i = 0; i < TheSeller->SList.size(); i++)
		{
			printf("\n%s for %i", temp1->data->name.c_str(), ((Item*)temp1->data)->price);//((Item*)temp1->data)->price);
			//printf("%i\n", ((Item*)temp1->data)->price);
			temp1 = temp1->next;
		}
	}
}
void World::movement()
{
	
	
	char command[COMMANDBUFFER];
	bool firsttimeinloop = true;
	unsigned int currenttime = 0;
	unsigned int initialtime = 0;
	unsigned int charcommandnum = 0;
	MyString option;
	//timeGetTime()
	initialtime = GetTickCount();
	
	while(command != "q\0"){
		//Executa el codi cada x milisegons (DELAY)
		currenttime = GetTickCount();
		if (currenttime >= (initialtime + DELAY)){
			if (world->ThePlayer->life <= 0)
			{
				printf("\n\nYOU DIED!\n\n");
				system("pause");
				return;
			}
			if (world->TheKiller->life <= 0)
			{
				printf("\n You've killed the Killer!!!!!\n\n");
				printf("\n\nYOU WON!\n\n");
				system("pause");
				return;
			}
			//printf("Hy.\n
			//system("cls");
			printf("You are  at: %s\n", world->ThePlayer->location->name);
			printItems();
			if (command != NULL)
			{
				printf("Your command is: %s\n", command);
			}
			
			printf("You have %i dollars\n", world->ThePlayer->money);
			initialtime = currenttime;
			for (int i = 0; i < entities.size(); i++)
			{
				entities[i]->Update();
			}
			

			if (ThePlayer->attacking == true)
			{
				ThePlayer->attack();
				//ThePlayer->attacking = false;
				//
				//return;
			}
			
		}
		
		//kbhit 
		else
		{

			if (_kbhit())
			{
				
				 if (charcommandnum < (COMMANDBUFFER - 2)){
					command[charcommandnum] = _getch();
					command[charcommandnum + 1] = '\0';
					//printf("String: %s\n", command);//prints command

					charcommandnum++;
					if (command[charcommandnum - 1] == '\r'){//prints full comand
						printf("Your command is: %s\n", command);

						command[charcommandnum - 1] = '\0';
						charcommandnum = 0;
						option = command;

						Vector <MyString> tokens = option.tokenize(" ", command);
						words = tokens;
						temporal = command;
						//	command = "\0";
						if (option == "q" || option == "quit")
						{
							break;
						}
						else if (option.empty() || option == "\r")
						{
							continue;
						}
						if (TheKiller->Killstate != FIGHT)
						{
						if (tokens[0] == "go" && tokens.size() >= 1)
						{

							if (tokens.size() >= 2)
							{
								if (tokens[1] == "north")
								{
									ThePlayer->Go(north);

								}
								if (tokens[1] == "west")
								{
									ThePlayer->Go(west);

								}
								if (tokens[1] == "south")
								{
									ThePlayer->Go(south);

								}
								if (tokens[1] == "east")
								{
									ThePlayer->Go(east);

								}
								continue;
							}
							else
							{
								printf("\nWhere\n");
							}

						}
						}
						if (TheKiller->Killstate != FIGHT)
						{
						 if (tokens[0] == "look" && tokens.size() >= 1)
						{
							if (tokens.size() >= 2)
							{
								if (tokens[1] == "north")
								{
									ThePlayer->look(north);

								}
								if (tokens[1] == "west")
								{
									ThePlayer->look(west);

								}
								if (tokens[1] == "south")
								{
									ThePlayer->look(south);

								}
								if (tokens[1] == "east")
								{
									ThePlayer->look(east);

								}
								continue;
							}
							else
							{
								printf("\nYou are in : %s\n", ThePlayer->location->description);
							}


						}
						}
						if (TheKiller->Killstate != FIGHT)
						{
						 if (tokens[0] == "open" && tokens.size() >= 1)
						{
							ThePlayer->Open();
						}
						else if (tokens[0] == "close" && tokens.size() >= 1)
						{
							ThePlayer->Close();
						}
						else if (tokens[0] == "pick" && tokens.size() >= 1)
						{
							if (tokens.size() >= 2)
							{
								ThePlayer->Pick(tokens);
								continue;
							}
							else
							{
								printf("\nWhat do you want to pick\n");
							}
						}
						else if (tokens[0] == "drop" && tokens.size() >= 1)
						{
							if (tokens.size() >= 2)
							{
								ThePlayer->Drop(tokens);
								continue;
							}
							else
							{
								printf("\nWhat do you want to drop\n");
							}
						}
						else if (tokens[0] == "equip" && tokens.size() >= 1)
						{
							if (tokens.size() >= 2)
							{
								ThePlayer->Equip(tokens);
								continue;
							}
							else
							{
								printf("\nWhat do you want to equip\n");
							}
						}
						else if (tokens[0] == "unequip" && tokens.size() >= 1)
						{
							if (tokens.size() >= 2)
							{
								ThePlayer->Unequip(tokens);
								continue;
							}
							else
							{
								printf("\nWhat do you want to unequip\n");
							}
						}
						}
						if (tokens.size() == 2)
						{
							if (tokens[0] == "buy" && tokens[1] == "seller")
							{
								printShop();
							}
							if (tokens[0] == "attack" && tokens[1] == "killer")
							{
								ThePlayer->attack();
							}
							if (tokens[0] == "use" && tokens[1] == "ticket")
							{
								ThePlayer->use(tokens);
							}
						}
						if (TheKiller->Killstate != FIGHT)
						{
							if (tokens.size() >= 4)
							{
								if (tokens[0] == "put" && tokens.size() >= 1 && tokens[3] == "bag")
								{

									ThePlayer->Put(tokens);
								}
								else if (tokens[0] == "get" && tokens.size() >= 1 && tokens[3] == "bag")
								{
									ThePlayer->Get(tokens);
								}
								else if (tokens[0] == "buy" && tokens.size() >= 1 && tokens[3] == "seller")
								{
									ThePlayer->buy(tokens);
								}
								else if (tokens[0] == "sell" && tokens.size() >= 1 && tokens[3] == "seller")
								{
									ThePlayer->sell(tokens);
								}
							}
						}


					}

				}
				else{
					command[COMMANDBUFFER - 1] = '\0';
				}

			}
		}
	}
	

	system("pause");
//	return 0;
}