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
	entities.Push_back(new Room("South Train Station", "This is the south train station. There is a train, but it doesn't seem to work.\n", false, true,ROOM));
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
	entities.Push_back(new Item("flashlight", "This is a flashlight", (Room*)entities[3], false, false, false, false, ITEM));
	//item 1
	entities.Push_back(new Item("crowbar", "This is a crowbar", (Room*)entities[5], false, false, false, false, ITEM));
	//item 2
	entities.Push_back(new Item("ticket", "This is a Train Ticket", (Room*)entities[3], false, false, false, false, ITEM));
	//item 3
	entities.Push_back(new Item("knife", "This is a Knife", (Room*)entities[8], false, false, false, false, ITEM));
	//item 4
	entities.Push_back(new Item("bag", "This is a bag", (Room*)entities[2], false, false, true, false, ITEM));
	
	//CREATURES
	//NPC
	entities.Push_back(new talkingNPC("Walking vendor", "Robot walking vendor", (Room*)entities[1], 100, CREATURE));
	//player
	entities.Push_back(new Player("Player", "Player", (Room*)entities[0], 100, CREATURE));

	ThePlayer = (Player*)entities[40];

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
			//printf("Hy.\n
			//system("cls");
			printf("You are  at: %s\n", world->ThePlayer->location->name);
			printf("Your command is: %s\n", command);
			initialtime = currenttime;
			for (int i = 0; i < entities.size(); i++)
			{
				entities[i]->Update();
			}
			
		}

		//kbhit 
		
		if (_kbhit())
		{
			for (int i = 0; i < entities.size(); i++)
			{
			entities[i]->Update();
			}
			
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
						if (option == "q" || option == "quit")
						{
							break;
						}
						if (option.empty() || option == "\r")
						{
							continue;
						}
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

				}
				else{
					command[COMMANDBUFFER - 1] = '\0';
				}
			
		}
	}
	

	system("pause");
//	return 0;
}