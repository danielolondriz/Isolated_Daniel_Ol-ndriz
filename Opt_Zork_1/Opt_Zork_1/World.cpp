#include "World.h"

#include<stdio.h>

World::World(){
	createWorld();
	TheString = new MyString();
	first = new MyString();
	second = new MyString();
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
void World::go(const MyString*word, const Exit* exit, Player*player, const dir dir)const
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



}
void World::compare(const MyString* word1, const MyString* word2)
{
	if (*word1 == "go")
	{
		printf("HEEEY");/*
		if (*word2 == "north")
		{
		//go(word2->c_str, exit[0], player, north);

		}
		if (*word2 == "west")
		{
		//go(word2->c_str, exit[0], player, west);
		}
		if (*word2 == "south")
		{
		//go(word2->c_str, exit[0], player, south);
		}
		if (*word2 == "east")
		{
		//go(word2->c_str, exit[0], player, east);
		}
		}
		else if (*word1 == "look")

		{

		if (*word2 == "north")
		{
		//look(word2->c_str, exit[0], player, north);

		}
		if (*word2 == "west")
		{
		//look(word2->c_str, exit[0], player, west);
		}
		if (*word2 == "south")
		{
		//look(word2->c_str, exit[0], player, south);
		}
		if (*word2 == "east")
		{
		//look(word2->c_str, exit[0], player, east);
		}
		}
		else if (word2 == nullptr)
		{
		if (*word1 == "north")
		{
		//go(word1->c_str, exit[0], player, north);

		}
		if (*word1 == "west")
		{
		//go(word1->c_str, exit[0], player, west);
		}
		if (*word1 == "south")
		{
		//go(word1->c_str, exit[0], player, south);
		}
		if (*word1 == "east")
		{
		//go(word1->c_str, exit[0], player, east);
		}

		}*/
	}

}


void World::movement()
{

	char answer [20];
	char *Counter;
	
	player->location = EntrancePlaza;
	printf("You are now in %s\n", player->location->name);
	
		printf("What do you want to do?\n");
		gets_s(answer);
		TheString->Get(answer);
	//	TheString->GetWords(answer,first,second);
		//printf("%s", first->c_str());
		//compare(*first,second);







}