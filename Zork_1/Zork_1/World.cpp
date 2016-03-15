
#include "World.h"
#include<stdio.h>
#include<cmath>
#include <string.h>


World::World()
{


	room = new Room[12];
	exit = new Exit[22];
	player = new Player;
}
World::~World()
{
	delete[] room;
	delete[] exit;
	delete[] player;
}
void const World::createWorld()
{
	int i;
	i = 0;
	//ROOMS
	strcpy_s(((room + i)->name), "Entrance Plaza");
	strcpy_s(((room + i)->description), "This is the Entrance Plaza of the park. A rusty statue stands in the middle.\n In the North there is the main street.\n And in the east you can see a Train Station ");
	i = 1; //Main Street
	strcpy_s(((room + i)->name), "Main Street");
	strcpy_s(((room + i)->description), "This is the glorious Main Street. On your left you can see a dark haunted house. On your right a Shop, and in front of you the street continues.");
	i = 2; //Haunted House
	strcpy_s(((room + i)->name), "Haunted House");
	strcpy_s(((room + i)->description), "It's such a dark place, that noone would like to be in.");
	i = 3; //Shop
	strcpy_s(((room + i)->name), "Shop");
	strcpy_s(((room + i)->description), "The Shop looks quite abandoned. On one side you can see a selling machine.");
	i = 4; //End of the street
	strcpy_s(((room + i)->name), "End of the Street");
	strcpy_s(((room + i)->description), "Looks like the Main street ends here. You can either go left to  the Ferris Wheel, or go down to your right, where a dark looking underground passage is located.");
	i = 5; //Ferris Wheel
	strcpy_s(((room + i)->name), "Ferris Wheel");
	strcpy_s(((room + i)->description), "You stand in front of the rusted old Ferris Wheel. it doesn't seem to work");
	i = 6; //Underground Passage
	strcpy_s(((room + i)->name), "Underground Passage");
	strcpy_s(((room + i)->description), "Between all the rubish you can see light coming from the north");
	i = 7; //Fountain Plaza
	strcpy_s(((room + i)->name), "Fountain Plaza");
	strcpy_s(((room + i)->description), "A big Plaza stands in front of you. An abandoned Roller coaster can be seen on your right, a Dock far in the North. Another building can be seen on your left with the name north train Station on it.");
	i = 8; //Roller coaster
	strcpy_s(((room + i)->name), "Roller Coaster");
	strcpy_s(((room + i)->description), "Since the power is off, the old looking Roller coaster wont work.\n");
	i = 9; //Dock
	strcpy_s(((room + i)->name), "Dock");
	strcpy_s(((room + i)->description), "A Boat stands in front of you but, it's cabin is locked with a keychain.\n");
	i = 10; //Train station
	strcpy_s(((room + i)->name), "South Train Station");
	strcpy_s(((room + i)->description), "This is the south train station. There is a train, but it doesn't seem to work.\n");
	i = 11; //Train Station
	strcpy_s(((room + i)->name), "North Train Station");
	strcpy_s(((room + i)->description), "This is the magestic North train station. Yet no train seems to be coming...\n");
	//EXITS
	i = 0;//Plaza North
	(exit + i)->origin = room + 0;
	(exit + i)->destination = room + 1;
	(exit + i)->direction = north;
	(exit + i)->close = false;
	i = 1; //Plaza East
	(exit + i)->origin = room + 0;
	(exit + i)->destination = room + 10;
	(exit + i)->direction = west;
	(exit + i)->close = false;
	i = 2; //Main street North
	(exit + i)->origin = room + 1;
	(exit + i)->destination = room + 4;
	(exit + i)->direction = north;
	(exit + i)->close = false;
	i = 3; //Main street South
	(exit + i)->origin = room + 1;
	(exit + i)->destination = room + 0;
	(exit + i)->direction = south;
	(exit + i)->close = false;
	i = 4; //Main street West
	(exit + i)->origin = room + 1;
	(exit + i)->destination = room + 2;
	(exit + i)->direction = west;
	(exit + i)->close = false;
	i = 5; //Main street East
	(exit + i)->origin = room + 1;
	(exit + i)->destination = room + 3;
	(exit + i)->direction = east;
	(exit + i)->close = false;
	i = 6; //Shop west
	(exit + i)->origin = room + 3;
	(exit + i)->destination = room + 1;
	(exit + i)->direction = west;
	(exit + i)->close = false;
	i = 7; //Haunted House East
	(exit + i)->origin = room + 2;
	(exit + i)->destination = room + 1;
	(exit + i)->direction = east;
	(exit + i)->close = false;
	i = 8; //End of Street South
	(exit + i)->origin = room + 4;
	(exit + i)->destination = room + 1;
	(exit + i)->direction = south;
	(exit + i)->close = false;
	i = 9; //End of Street West
	(exit + i)->origin = room + 4;
	(exit + i)->destination = room + 5;
	(exit + i)->direction = west;
	(exit + i)->close = false;
	i = 10; //End of Street East
	(exit + i)->origin = room + 4;
	(exit + i)->destination = room + 6;
	(exit + i)->direction = east;
	(exit + i)->close = false;
	i = 11; //Ferris Wheel east
	(exit + i)->origin = room + 5;
	(exit + i)->destination = room + 4;
	(exit + i)->direction = east;
	(exit + i)->close = false;
	i = 12; //Underground West
	(exit + i)->origin = room + 6;
	(exit + i)->destination = room + 4;
	(exit + i)->direction = west;
	(exit + i)->close = false;
	i = 13; //Underground North
	(exit + i)->origin = room + 6;
	(exit + i)->destination = room + 7;
	(exit + i)->direction = north;
	(exit + i)->close = false;
	i = 14; //Plaza North
	(exit + i)->origin = room + 7;
	(exit + i)->destination = room + 9;
	(exit + i)->direction = north;
	(exit + i)->close = false;
	i = 15; //Plaza South
	(exit + i)->origin = room + 7;
	(exit + i)->destination =room + 6;
	(exit + i)->direction = south;
	(exit + i)->close = false;
	i = 16; //Plaza West
	(exit + i)->origin = room + 7;
	(exit + i)->destination = room + 11;
	(exit + i)->direction = west;
	(exit + i)->close = false;
	i = 17; //Plaza East
	(exit + i)->origin = room + 7;
	(exit + i)->destination = room + 8;
	(exit + i)->direction =east;
	(exit + i)->close = false;
	i = 18; //Roller coaster west
	(exit + i)->origin = room + 8;
	(exit + i)->destination = room + 7;
	(exit + i)->direction = west;
	(exit + i)->close = false;
	i = 19; //NTrain east
	(exit + i)->origin = room + 11;
	(exit + i)->destination = room + 7;
	(exit + i)->direction = east;
	(exit + i)->close = false;
	i = 20; //STrain West
	(exit + i)->origin = room + 10;
	(exit + i)->destination = room + 0;
	(exit + i)->direction = west;
	(exit + i)->close = false;
	i = 21; //Dock South
	(exit + i)->origin = room +9;
	(exit + i)->destination = room + 7;
	(exit + i)->direction =south;
	(exit + i)->close = false;






}
void World::movement()
{
	char answer[20];
	int i = 0;
	int j = 0;
	char *Counter;
	char *first;
	char *second;
	//actions
	char *look = "look";
	char *go = "go";
	char *help = "help";
	char *quit = "quit";
	//directions
	char *North = "north";
	char *South = "south";
	char *East = "east";
	char *West = "west";
	char *n = "n";
	char *s = "s";
	char *e = "e";
	char *w = "w";
	//Introduction

	printf("You are now in the %s\n", ((room + j)->name));
	//Asks for the action
	do
	{

		do
		{
			printf("What do you want to do?\n");
			gets_s(answer);
			//saves the 2 words
			first = strtok_s(answer, " ", &Counter);
		} while (first == NULL);
		second = strtok_s(NULL, " ", &Counter);


		if (second == NULL)
		{

			//ONE WORD
			if (*first == *North || *first == *n)
			{
				for (i = 0; i < 22; i++)
				{
					if (((exit + i)->direction == north) && (exit + i)->origin == (room + i))
					{
						//changes Room to destination
						(*(room + i) = (*(exit + i)->destination));
						printf("You are now in the %s %i\n", ((room + i)->name), i);
					}
				}
			}
			if (*first == *West || *first == *w)
			{
				for (i = 0; i < 22; i++)
				{
					if (((exit + i)->direction == west) && (exit + i)->origin == (room + j))
					{
						//changes Room to destination
						(*(room + j) = (*(exit + i)->destination));
						printf("You are now in the %s %i\n", ((room + j)->name), &j);
					}
				}
			}
		}
	} while (first != NULL);
	
}