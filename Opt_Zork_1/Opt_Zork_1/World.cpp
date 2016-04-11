#include "World.h"

#include<stdio.h>

World::World(){
	createWorld();
}
World::~World(){}
void World::createWorld()
{
	
	player = new Player();
	
	//ROOMS
	//	Room *rooms[12];
	EntrancePlaza = new Room("Entrance Plaza", "This is the Entrance Plaza of the park. A rusty statue stands in the middle.\n In the North there is the main street.\n And in the east you can see a Train Station");

	Room *MainStreet = new Room("Main Street", "This is the glorious Main Street. On your left you can see a dark haunted house. On your right a Shop, and in front of you the street continues.");

	Room *HauntedHouse = new Room("Haunted House", "It's such a dark place, that noone would like to be in.");

	Room *Shop = new Room("Shop", "The Shop looks quite abandoned. On one side you can see a selling machine.");

	Room *EndofStreet = new Room("End of the Street", "Looks like the Main street ends here. You can either go left to  the Ferris Wheel, or go down to your right, where a dark looking underground passage is located.");

	Room *FerrisWheel = new Room("Ferris Wheel", "You stand in front of the rusted old Ferris Wheel. it doesn't seem to work");

	Room *Underground = new Room("Underground Passage", "Between all the rubish you can see light coming from the north");

	Room *Fountain = new Room("Fountain Plaza", "A big Plaza stands in front of you. An abandoned Roller coaster can be seen on your right, a Dock far in the North. Another building can be seen on your left with the name north train Station on it.");

	Room *RollerCoaster = new Room("Roller Coaster", "Since the power is off, the old looking Roller coaster wont work.\n");

	Room *Dock = new Room("Dock", "A Boat stands in front of you but, it's cabin is locked with a keychain.\n");

	Room *STrainStation = new Room("South Train Station", "This is the south train station. There is a train, but it doesn't seem to work.\n");

	Room *NTrainStation = new Room("North Train Station", "This is the magestic North train station. Yet no train seems to be coming...\n");
	//EXITS
	//Exit* exit[22];
	exit[0] = new Exit(EntrancePlaza, MainStreet, north, false);
	//printf("%s\n", exit[0]->origin->name);

	exit[1] = new Exit(EntrancePlaza, STrainStation, west, false);

	exit[2] = new Exit(MainStreet, EndofStreet, north, false);

	exit[3] = new Exit(MainStreet, EntrancePlaza, south, false);

	exit[4] = new Exit(MainStreet, Shop, east, true);

	exit[5] = new Exit(MainStreet, HauntedHouse, west, false);

	exit[6] = new Exit(EndofStreet, FerrisWheel, west, false);

	exit[7] = new Exit(EndofStreet, Underground, east, false);

	exit[8] = new Exit(EndofStreet, MainStreet, south, false);

	exit[9] = new Exit(FerrisWheel, EndofStreet, east, false);

	exit[10] = new Exit(Underground, Fountain, north, false);

	exit[11] = new Exit(Underground, EndofStreet, west, false);

	exit[12] = new Exit(Fountain, Underground, south, false);

	exit[13] = new Exit(Fountain, Dock, north, false);

	exit[14] = new Exit(Fountain, RollerCoaster, east, false);

	exit[15] = new Exit(Fountain, NTrainStation, west, false);

	exit[16] = new Exit(NTrainStation, Fountain, east, false);

	exit[17] = new Exit(RollerCoaster, Fountain, west, false);

	exit[18] = new Exit(Dock, Fountain, south, false);

	exit[19] = new Exit(STrainStation, EntrancePlaza, east, false);

	exit[20] = new Exit(Shop, MainStreet, west, false);

	exit[21] = new Exit(HauntedHouse, MainStreet, east, false);

}
void World::go(const char*word,const Exit* exit,Player*player, const dir dir)const
{
	int i;
	for (i = 0; i < 22; i++)
	{
		if (exit[i].direction == dir)
		{
			if (player->location == exit[i].origin)
			{
				player->location = exit[i].destination;
				
				break;
			}
		}
		
		
	}
	printf("You are now in %s\n", player->location->name);
	
	
}
void World::look(const char*word, const Exit* exit, Player*player, const dir dir)const
{
	int i;
	for (i = 0; i < 22; i++)
	{
		if (exit[i].direction == dir)
		{
			if (player->location == exit[i].origin)
			{
				
				printf("You can see %s\n", exit[i].destination->description);
				break;
			}
		}


	}
	printf("You are now in %s\n", player->location->name);


}

void World::compareGO(const char* word)
{

	if (strcmp(word, "north") == 0)
	{
		go(word, exit[0], player, north);

	}
	if (strcmp(word, "west") == 0)
	{
		go(word, exit[0], player, west);
	}
	if (strcmp(word, "south") == 0)
	{
		go(word, exit[0], player, south);
	}
	if (strcmp(word, "east") == 0)
	{
		go(word, exit[0], player, east);
	}

}
void World::compareLOOK(const char* word)
{

	if (strcmp(word, "north") == 0)
	{
		look(word, exit[0], player, north);

	}
	if (strcmp(word, "west") == 0)
	{
		look(word, exit[0], player, west);
	}
	if (strcmp(word, "south") == 0)
	{
		look(word, exit[0], player, south);
	}
	if (strcmp(word, "east") == 0)
	{
		look(word, exit[0], player, east);
	}

}
void World::movement()
{

	char answer[20];
	char *Counter;
	char *first;
	char *second;
	player->location = EntrancePlaza;
	printf("You are now in %s\n", player->location->name);
	do
	{
		printf("What do you want to do?\n");
		gets_s(answer);
		//saves the 2 words
		first = strtok_s(answer, " ", &Counter);
	} while (first == NULL);//while there is no answer
	second = strtok_s(NULL, " ", &Counter);
	compareGO(first);
	if (strcmp(first, "go") == 0)
	{
		compareGO(second);

	}
	if (strcmp(first, "look") == 0)
	{
		compareLOOK(second);

	}
	
		
	
	
	
}