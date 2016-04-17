#include "World.h"

#include<stdio.h>

World::World(){
	createWorld();
	TheString = new MyString();
	//first = new MyString();
	//second = new MyString();
}
World::~World(){}
void World::createWorld()
{
	Room *EntrancePlaza;
	Room *MainStreet;
	Room *HauntedHouse;
	Room *Shop;
	Room *EndofStreet;
	Room *FerrisWheel;
	Room *Underground;
	Room *Fountain;
	Room *RollerCoaster;
	Room *Dock;
	Room *STrainStation;
	Room *NTrainStation;
	player.Push_back( new Player());
	
	//ROOMS
	{
		rooms.Push_back(EntrancePlaza = new Room("Entrance Plaza", "This is the Entrance Plaza of the park. A rusty statue stands in the middle.\n In the North there is the main street.\n And in the east you can see a Train Station"));

		rooms.Push_back(MainStreet = new Room("Main Street", "This is the glorious Main Street. On your left you can see a dark haunted house. On your right a Shop, and in front of you the street continues."));

		rooms.Push_back(HauntedHouse = new Room("Haunted House", "It's such a dark place, that noone would like to be in."));

		rooms.Push_back(Shop = new Room("Shop", "The Shop looks quite abandoned. On one side you can see a selling machine."));

		rooms.Push_back(EndofStreet = new Room("End of the Street", "Looks like the Main street ends here. You can either go left to  the Ferris Wheel, or go down to your right, where a dark looking underground passage is located."));

		rooms.Push_back(FerrisWheel = new Room("Ferris Wheel", "You stand in front of the rusted old Ferris Wheel. it doesn't seem to work"));

		rooms.Push_back(Underground = new Room("Underground Passage", "Between all the rubish you can see light coming from the north"));

		rooms.Push_back(Fountain = new Room("Fountain Plaza", "A big Plaza stands in front of you. An abandoned Roller coaster can be seen on your right, a Dock far in the North. Another building can be seen on your left with the name north train Station on it."));

		rooms.Push_back(RollerCoaster = new Room("Roller Coaster", "Since the power is off, the old looking Roller coaster wont work.\n"));

		rooms.Push_back(Dock = new Room("Dock", "A Boat stands in front of you but, it's cabin is locked with a keychain.\n"));

		rooms.Push_back(STrainStation = new Room("South Train Station", "This is the south train station. There is a train, but it doesn't seem to work.\n"));

		rooms.Push_back(NTrainStation = new Room("North Train Station", "This is the magestic North train station. Yet no train seems to be coming...\n"));
	}
	//EXITS
	//Exit* exit[22];
	exit.Push_back(new Exit(EntrancePlaza, MainStreet, north, false,"main street","you see the Main street"));
	//printf("%s\n", exit[0]->origin->name);

	exit.Push_back(new Exit(EntrancePlaza, STrainStation, west, false,"Train Station", "you see the Train station"));

	exit.Push_back(new Exit(MainStreet, EndofStreet, north, false, "End of street", "you see theEnd of street"));

	exit.Push_back(new Exit(MainStreet, EntrancePlaza, south, false, "Entrance Plaza", "you see the Entrance Plaza"));

	exit.Push_back(new Exit(MainStreet, Shop, east, true, "Shop", "you see the Shop"));

	exit.Push_back(new Exit(MainStreet, HauntedHouse, west, false, "haunted House", "you see the haunted House"));

	exit.Push_back(new Exit(EndofStreet, FerrisWheel, west, false, "FerrisWheels", "you see the FerrisWheels"));

	exit.Push_back(new Exit(EndofStreet, Underground, east, false, "Underground", "you see the Underground"));

	exit.Push_back(new Exit(EndofStreet, MainStreet, south, false, "main street", "you see the Main street"));

	exit.Push_back(new Exit(FerrisWheel, EndofStreet, east, false, "End of street", "you see the End of street"));

	exit.Push_back(new Exit(Underground, Fountain, north, false, "Fountain Plaza", "you see the Fountain Plaza"));

	exit.Push_back(new Exit(Underground, EndofStreet, west, false, "End of street", "you see the End of street"));

	exit.Push_back(new Exit(Fountain, Underground, south, false, "Underground", "you see the Underground Passage"));

	exit.Push_back(new Exit(Fountain, Dock, north, false, "Dock", "you see the Dock"));

	exit.Push_back(new Exit(Fountain, RollerCoaster, east, false, "Roller Coaster", "you see the Roller Coaster"));

	exit.Push_back(new Exit(Fountain, NTrainStation, west, false, "North Train Station", "you see the North Train Station"));

	exit.Push_back(new Exit(NTrainStation, Fountain, east, false, "Fountain Plaza", "you see the Fountain Plaza"));

	exit.Push_back(new Exit(RollerCoaster, Fountain, west, false, "Fountain Plaza", "you see the Fountain Plaza"));

	exit.Push_back(new Exit(Dock, Fountain, south, false, "Fountain Plaza", "you see the Fountain Plaza"));

	exit.Push_back(new Exit(STrainStation, EntrancePlaza, east, false, "Entrance Plaza", "you see the Entrance Plaza"));
	printf("HOLA%i\n", exit[1]->direction);
	exit.Push_back(new Exit(Shop, MainStreet, west, false, "main street", "you see the Main street"));

	exit.Push_back(new Exit(HauntedHouse, MainStreet, east, false, "main street", "you see the Main street"));
	

}

void World::go( const Vector<Exit*>& exit, Vector <Player*>& player, const dir dir)const
{
	int i;
	for (i = 0; i < 22; i++)
	{
		
		if (exit[i]->direction == dir)
		{
			if (player[0]->location == exit[i]->origin)
			{
				player[0]->location = exit[i]->destination;

				break;
			}
		}


	}
	printf("You are now in %s\n", player[0]->location->name.c_str());


}
void World::look(const Vector<Exit*>& exit, Vector <Player*>& player, const dir dir)const
{
	int i;
	for (i = 0; i < 22; i++)
	{
		if (exit[i]->direction == dir)
		{
			if (player[0]->location == exit[i]->origin)
			{

				printf("%s\n", exit[i]->description);
				break;
			}
		}


	}



}
void World::compare(Vector<MyString>& word)
{
	unsigned int size = word.size();
	if (size == 1)// 1 WORD
	{
		if (word[0] == "north")
		{
			go(exit, player, north);
		}
		if (word[0] == "west")
		{
			go(exit, player, west);
		}
		if (word[0] == "south")
		{
			go(exit, player, south);
		}
		if (word[0] == "east")
		{
			go(exit, player, east);
		}
		if (word[0] == "go")
		{
			printf("Where?\n");
		}
		if (word[0] == "look")
		{
			printf("%s\n", player[0]->location->description);
		}
	}
	if (size == 2)//2 WORDS
	{

		if (word[0] == "go")
		{
			
			if (word[1] == "north")
			{
				go(exit, player, north);
			}
			if (word[1] == "west")
			{
				go(exit, player, west);
			}
			if (word[1] == "south")
			{
				go(exit, player, south);
			}
			if (word[1] == "east")
			{
				go(exit, player, east);
			}
		}
		if (word[0] == "look")
		{
			
			if (word[1] == "north")
			{
				look(exit, player, north);
			}
			if (word[1] == "west")
			{
				look(exit, player, west);
			}
			if (word[1] == "south")
			{
				look(exit, player, south);
			}
			if (word[1] == "east")
			{
				look(exit, player, east);
			}
		}
	}


		}
	




void World::movement()
{
	Vector <MyString> tokens;
	MyString StringAnswer;
	
	char answer [20];
	char* quit = "quit";
	char *Counter;
	//rooms[4]->name;
	player[0]->location = rooms[0];
	printf("You are now in %s\n", player[0]->location->name.c_str());
	
	do
	{
		printf("What do you want to do?\n");
		gets_s(answer);
		StringAnswer.Get(answer);
		if (StringAnswer != "quit")
		{
			//break; //breaks the loop so that it doesn't do all the other functions & methods
		}
		
		tokens = TheString->tokenize(" ", answer);
		//printf("%s", tokens[1]);

		//	TheString->GetWords(answer,first,second);
		//printf("%s", first->c_str());
		compare(tokens);
	} while (StringAnswer != "quit");






}