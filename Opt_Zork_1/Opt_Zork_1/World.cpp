#include "World.h"
#include<stdio.h>
#define MAX_ITEMS 5
#define MAX_INVENTORY 3
#define MAX_EQUIPPED 2
#define MAX_BOX 2
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
		rooms.Push_back(EntrancePlaza = new Room("Entrance Plaza", "This is the Entrance Plaza of the park. A rusty statue stands in the middle.\n In the North there is the main street.\n And in the west you can see a Train Station", false, true));

		rooms.Push_back(MainStreet = new Room("Main Street", "This is the glorious Main Street. On your left you can see a dark haunted house. On your right a Shop, and in front of you the street continues.", false, true));

		rooms.Push_back(HauntedHouse = new Room("Haunted House", "It's such a dark place, that noone would like to be in.",true,false));

		rooms.Push_back(Shop = new Room("Shop", "The Shop looks quite abandoned. On one side you can see a selling machine.", false, true));

		rooms.Push_back(EndofStreet = new Room("End of the Street", "Looks like the Main street ends here. You can either go left to  the Ferris Wheel, or go down to your right, where a dark looking underground passage is located.", false, true));

		rooms.Push_back(FerrisWheel = new Room("Ferris Wheel", "You stand in front of the rusted old Ferris Wheel. it doesn't seem to work", false, true));

		rooms.Push_back(Underground = new Room("Underground Passage", "Between all the rubish you can see light coming from the north",true,false));

		rooms.Push_back(Fountain = new Room("Fountain Plaza", "A big Plaza stands in front of you. An abandoned Roller coaster can be seen on your right, a Dock far in the North. Another building can be seen on your left with the name north train Station on it.", false, true));

		rooms.Push_back(RollerCoaster = new Room("Roller Coaster", "Since the power is off, the old looking Roller coaster wont work.\n", false, true));

		rooms.Push_back(Dock = new Room("Dock", "A Boat stands in front of you but, it's cabin is locked with a keychain.\n", false, true));

		rooms.Push_back(STrainStation = new Room("South Train Station", "This is the south train station. There is a train, but it doesn't seem to work.\n", false, true));

		rooms.Push_back(NTrainStation = new Room("North Train Station", "This is the magestic North train station. Yet no train seems to be coming...\n", false, true));
	}
	//ITEMS
	items.Push_back(new Item("flashlight", "This is a flashlight", Shop, false, false, false, false));

	items.Push_back(new Item("crowbar", "This is a crowbar", FerrisWheel, false, false, false, false));

	items.Push_back(new Item("ticket", "This is a Train Ticket", Shop, false, false, false, false));

	items.Push_back(new Item("knife", "This is a Knife", RollerCoaster, false, false, false, false));

	items.Push_back(new Item("bag", "This is a bag", HauntedHouse, false, false,true,false));
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
	
	exit.Push_back(new Exit(Shop, MainStreet, west, true, "main street", "you see the Main street"));

	exit.Push_back(new Exit(HauntedHouse, MainStreet, east, false, "main street", "you see the Main street"));
	

}
void World::travel()
{
	if (player[0]->location == rooms[10] )
	{
		
		if (items[2]->inventory == true)
		{
			
			player[0]->location = rooms[11];
		}
	}
	else if (player[0]->location == rooms[11])
	{
		if (items[2]->inventory == true)
		{
			
			player[0]->location = rooms[10];
		}
	}

}
void World::take( Vector<MyString>& words, unsigned int& capacity)const
{
	
		
		for (int i = 0; i < MAX_ITEMS; i++)
		{
			
			if (items[i]->name == words[1].c_str())
			{
				
				if (items[i]->location == player[0]->location)
				{
					if (items[i]->inventory == false)
					{
						if (capacity < MAX_INVENTORY)
						{
							items[i]->inventory = true;
							printf("\n\nyou've picked the %s!\n\n", items[i]->name);
							capacity++;
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
void World::drop( Vector<MyString>& words, unsigned int& capacity)const
{

	
	for (int i = 0; i < MAX_ITEMS; i++)
	{

		if (items[i]->name == words[1].c_str())
		{
			if (items[i]->inventory == true)
			{

				items[i]->inventory = false;
				items[i]->equip = false;
				items[i]->location = player[0]->location;
				printf("\n\nYou've dropped the %s!\n\n", items[i]->name);
				capacity--;
			}
		}

	}

}
void World::equip( Vector<MyString>& words, unsigned int& capacity)const
{


	for (int i = 0; i < MAX_ITEMS; i++)
	{
		if (items[i]->name == words[1].c_str())
		{
			if (items[i]->inventory == true)
			{
				if (items[i]->equip == false)
				{
					if (capacity < MAX_EQUIPPED)
					{
						items[i]->equip = true;
						printf("\n\nYou've equipped the %s!\n\n", items[i]->name);
						capacity++;
					}
					else
					{
						printf("You have your hands full!\n\n");
					}
					
				}
			}
		}
		

	}

}
void World::unequip( Vector<MyString>& words, unsigned int& capacity)const
{


	for (int i = 0; i < MAX_ITEMS; i++)
	{
		if (items[i]->name == words[1].c_str())
		{
			if (items[i]->inventory == true)
			{
				if (items[i]->equip == true)
				{
					items[i]->equip = false;
					printf("\n\nYou've unequipped the %s!\n\n", items[i]->name);
					capacity--;
				}
			}
		}


	}

}

void World::go(  const dir dir)const
{
	int i;
	for (i = 0; i < 22; i++)
	{
		
		if (exit[i]->direction == dir)
		{
			if (player[0]->location == exit[i]->origin)
			{
				if (exit[i]->Door == false)
				{
					if (exit[i]->destination->lightopen == true)
					{
						player[0]->location = exit[i]->destination;
						break;
					}
					else
					{
						printf("\nYou don't want to go to a dark place like that\n");
					}
					
				}
				else
				{
					printf("Door is Locked\n");
				}
				
			}
		}


	}
	


}
void World::look( const dir dir)const
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
void World::lookItem( Vector<MyString>& word)
{
	for (int i = 0; i < MAX_ITEMS; i++)
	{
		if (items[i]->name == word[1].c_str())
		{
			if (items[i]->inventory == true)
			{
				if (items[i]->equip == true)
				{
					printf("\nyou have  %s equiped\n", items[i]->name);
				}
				else
				{
					printf("\nYou have  %s in your inventory!\n", items[i]->name);
				}
			}
		}
	}
}

void World::open( const dir dir)const
{
	int i;
	for (i = 0; i < 22; i++)
	{
		if (exit[i]->direction == dir)
		{
			if (player[0]->location == exit[i]->origin)
			{
				if (exit[i]->Door == true)
				{
					exit[i]->Door = false;
					printf("Door has opened\n");
					//break;
				}	
			}
			
		}
		if (exit[i]->destination == player[0]->location)
		{
			if (exit[i]->Door == true)
			{
				exit[i]->Door = false;
				//printf("Door has opened!!\n");
				//break;
			}
		}
		
	}
}
void World::close( const dir dir)const
{
	int i;
	
	//for (i = 0; i < 22; i++)
	{
		if (player[0]->location->name == exit[4]->origin->name || (player[0]->location == exit[20]->origin))
		{
			
			if (exit[4]->Door == false && exit[20]->Door == false)
			{
				exit[4]->Door = true;
				exit[20]->Door = true;
			
				printf("Door has closed\n");
			}
			
		}
		
		
	}
}
void World::inventory(Vector<Item*>& items)
{
	int empty = 0;
	for (int i = 0; i < MAX_ITEMS; i++)
	{
		if (items[i]->inventory == true)
		{
			printf("A %s\n", items[i]->name);
			empty++;
		}
	}
	if (empty == 0)
	{
		printf("Nothing\n\n");
	}
}
void World::ligth()
{
	for (int i = 0; i < 12; i++)
	{
		if (rooms[i]->light == true)
		{
			if (rooms[i]->lightopen == false)
			{
				rooms[i]->lightopen = true;
			}
		}
	}
}
void World::unligth()
{
	for (int i = 0; i < 12; i++)
	{
		if (rooms[i]->light == true)
		{
			if (rooms[i]->lightopen == true)
			{
				rooms[i]->lightopen = false;
			}
		}
	}
}
void World::put(Vector<MyString>& word, unsigned int& MAX, unsigned int& box)
{
	if (player[0]->location == items[4]->location)
	{
		for (int i = 0; i < MAX_ITEMS; i++)
		{
			if (word[1] == items[i]->name)
			{
				if (items[i]->inventory == true)
				{
					if (items[i]->IsBox == false)
					{
						if (box < MAX_BOX)
						{
							items[i]->InBox = true;
							items[i]->inventory = false;
							printf("you've put %s into the bag\n", items[i]->name);
							MAX--;
							box++;
						}
						else
						{
							printf("there is no room in the box\n");
						}
					}
				}
			}
		}
	}
	
}
void World::get(Vector<MyString>& word, unsigned int& MAX, unsigned int& box)
{
	if (player[0]->location == items[4]->location)
	{
		for (int i = 0; i < MAX_ITEMS; i++)
		{
			if (word[1] == items[i]->name)
			{
				if (items[i]->inventory == false)
				{
					if (items[i]->InBox == true)
					{
						if (MAX < MAX_INVENTORY)
						{
							items[i]->InBox = false;
							items[i]->inventory = true;
							printf("you've got the  %s from bag\n", items[i]->name);
							MAX++;
							box--;
						}

					}
				}
			}
		}
	}
}
void World::compare(Vector<MyString>& word, unsigned int& EQsize, unsigned int& INVsize, unsigned int& BOXsize)
{

	unsigned int size = word.size();
	if (size == 1)// 1 WORD
	{
		if (word[0] == "north" || word[0] == "n")
		{
			go(north);
		}
		if (word[0] == "west" || word[0] == "w")
		{
			go(west);
		}
		if (word[0] == "south" || word[0] == "s")
		{
			go(south);
		}
		if (word[0] == "east" || word[0] == "e")
		{
			go(east);
		}
		if (word[0] == "go")
		{
			printf("Where?\n");
		}
		if (word[0] == "look")
		{
			printf("%s\n", player[0]->location->description);
		}
		if (word[0] == "open")
		{
			printf("Which direction do you want to open?\n");
		}
		if (word[0] == "inventory" || word[0] == "i" || word[0] == "inv")
		{
			printf("You have:\n");
			inventory(items);

		}
	}
	if (size == 2)//2 WORDS
	{

		if (word[0] == "go")
		{

			if (word[1] == "north")
			{
				go(north);
			}
			if (word[1] == "west")
			{
				go(west);
			}
			if (word[1] == "south")
			{
				go(south);
			}
			if (word[1] == "east")
			{
				go(east);
			}
		}
		if (word[0] == "look")
		{

			if (word[1] == "north")
			{
				look(north);
			}
			if (word[1] == "west")
			{
				look(west);
			}
			if (word[1] == "south")
			{
				look(south);
			}
			if (word[1] == "east")
			{
				look(east);
			}
			if ((word[1] == "knife") || (word[1] == "crowbar") || (word[1] == "ticket") || (word[1] == "flashlight") || (word[1] == "box"))
			{
				lookItem(word);
			}
		}
		if (word[0] == "open")
		{

			if (word[1] == "north")
			{
				open(north);
			}
			if (word[1] == "west")
			{
				open(west);
			}
			if (word[1] == "south")
			{
				open(south);
			}
			if (word[1] == "east")
			{
				open(east);
			}
		}
		if (word[0] == "close")
		{

			if (word[1] == "north")
			{
				close(north);
			}
			if (word[1] == "west")
			{
				close(west);
			}
			if (word[1] == "south")
			{
				close(south);
			}
			if (word[1] == "east")
			{
				close(east);
			}
		}
		if (word[0] == "use")
		{
			if (word[1] == "ticket")
			{
				travel();
			}
		}
		if (word[0] == "pick")
		{
			if ((word[1] == "knife") || (word[1] == "crowbar") || (word[1] == "ticket") || (word[1] == "flashlight") || (word[1] == "bag"))
			{
				take(word, INVsize);
			}


		}
		if (word[0] == "drop")
		{
			if ((word[1] == "knife") || (word[1] == "crowbar") || (word[1] == "ticket") || (word[1] == "flashlight") || (word[1] == "bag"))
			{
				drop(word, INVsize);
			}

		}
		if (word[0] == "equip")
		{
			if ((word[1] == "knife") || (word[1] == "crowbar") || (word[1] == "ticket") || (word[1] == "box"))
			{
				equip(word, EQsize);
			}
			if ((word[1] == "flashlight"))
			{
				equip(word, EQsize);
				ligth();
			}
		}

		if (word[0] == "unequip")
		{
			if ((word[1] == "knife") || (word[1] == "crowbar") || (word[1] == "ticket") || (word[1] == "box"))
			{
				unequip(word, EQsize);
			}
			if ((word[1] == "flashlight"))
			{
				unequip(word, EQsize);
				unligth();
			}

		}


	}
	if (size == 4)
	{
		if (word[0] == "put")
		{
			if ((word[1] == "knife") || (word[1] == "crowbar") || (word[1] == "ticket") || (word[1] == "flashlight") || (word[1] == "box"))
			{
				if (word[2] == "into")
				{
					if (word[3] == "bag")
					{
						put(word, INVsize, BOXsize);
					}
				}
			}
		}
		if (word[0] == "get")
		{
			if ((word[1] == "knife") || (word[1] == "crowbar") || (word[1] == "ticket") || (word[1] == "flashlight") || (word[1] == "box"))
			{
				if (word[2] == "from")
				{
					if (word[3] == "bag")
					{
						get(word, INVsize, BOXsize);
					}
				}
			}
		}
	}
}
	


		
	




void World::movement()
{
	unsigned int INVsize = 0;
	unsigned int EQsize = 0;
	unsigned int BOXsize = 0;
	Vector <MyString> tokens;
	MyString StringAnswer;
	
	char answer [50];
	char* quit = "quit";
	char *Counter;
	//rooms[4]->name;
	player[0]->location = rooms[0];
	
	
		printf("You are now in %s\n", player[0]->location->name.c_str());
		printf("What do you want to do?\n");
		do
		{
			do
			{
				gets_s(answer);
				
			} while (answer[0]==NULL);
				StringAnswer.Answer(answer);
		} while (StringAnswer.empty());
		
		
		while ((StringAnswer != "quit") && (StringAnswer != "q"))
		{
			
			

			tokens = TheString->tokenize(" ", answer);
			//printf("%s", tokens[1]);

			//	TheString->GetWords(answer,first,second);
			//printf("%s", first->c_str());
			compare(tokens, EQsize, INVsize,BOXsize);

			printf("You are now in %s\n", player[0]->location->name.c_str());
			printf("What do you want to do?\n");
			do
			{
				do
				{
					gets_s(answer);

				} while (answer[0] == NULL);
				StringAnswer.Answer(answer);
			} while (StringAnswer.empty());

		}
		







}
