#include "World.h"
#include<stdio.h>
#include<cmath>
#include <string.h>
enum rooms {EntrancePlaza,MainStreet,HauntedHouse,Shop,EndofStreet,FerrisWheel,UndergroundPassage,FountainPlaza,RollerCoaster,Dock,STrainStation,NTrainStation};
	World::World()
{
	

	 room = new Room[12];
	 exit = new Exit[12];
}
World::~World()
{
	delete[] room;
	delete[] exit;
}
void World::createWorld()
{
	//Creates Rooms and Exits
	int i;
	i = 0; //Entrance plaza
	//Room
	strcpy_s(((room + i)->name), "Entrance Plaza");
	strcpy_s(((room + i)->description), "This is the Entrance Plaza of the park. A rusty statue stands in the middle.\n In the North there is the main street.\n And in the east you can see a Train Station ");
	//Exit
	((exit + i)->north)= MainStreet;
	((exit + i)->south)= EntrancePlaza;
	((exit + i)->east)= STrainStation;
	((exit + i)->west)= EntrancePlaza;


	i = 1; //Main Street
	//Room
	strcpy_s(((room + i)->name), "Main Street");
	strcpy_s(((room + i)->description), "This is the glorious Main Street. On your left you can see a dark haunted house. On your right a Shop, and in front of you the street continues.");
	//Exit
	((exit + i)->north) = EndofStreet;
	((exit + i)->south) = EntrancePlaza;
	((exit + i)->east) = Shop;
	((exit + i)->west) = HauntedHouse;


	i = 2; //Haunted House
	strcpy_s(((room + i)->name), "Haunted House");
	strcpy_s(((room + i)->description), "It's such a dark place, that noone would like to be in.");
	//Exit
	((exit + i)->north) = HauntedHouse;
	((exit + i)->south) = HauntedHouse;
	((exit + i)->east) = MainStreet;
	((exit + i)->west) = HauntedHouse;

	i = 3; //Shop
	strcpy_s(((room + i)->name), "Shop");
	strcpy_s(((room + i)->description), "The Shop looks quite abandoned. On one side you can see a selling machine.");
	//Exit
	((exit + i)->north) = Shop;
	((exit + i)->south) = Shop;
	((exit + i)->east) = Shop;
	((exit + i)->west) = MainStreet;


	i = 4; //End of the street
	strcpy_s(((room + i)->name), "End of the Street");
	strcpy_s(((room + i)->description), "Looks like the Main street ends here. You can either go left to  the Ferris Wheel, or go down to your right, where a dark looking underground passage is located.");
	//Exits
	((exit + i)->north) = EndofStreet;
	((exit + i)->south) = MainStreet;
	((exit + i)->east) = UndergroundPassage;
	((exit + i)->west) = FerrisWheel;

	i = 5; //Ferris Wheel
	strcpy_s(((room + i)->name), "Ferris Wheel");
	strcpy_s(((room + i)->description), "You stand in front of the rusted old Ferris Wheel. it doesn't seem to work");
	//Exits
	((exit + i)->north) = FerrisWheel;
	((exit + i)->south) = FerrisWheel;
	((exit + i)->east) = EndofStreet;
	((exit + i)->west) = FerrisWheel;

	i = 6; //Underground Passage
	strcpy_s(((room + i)->name), "Underground Passage");
	strcpy_s(((room + i)->description), "Between all the rubish you can see light coming from the north");
	//Exits
	((exit + i)->north) = FountainPlaza;
	((exit + i)->south) = UndergroundPassage;
	((exit + i)->east) = UndergroundPassage;
	((exit + i)->west) = EndofStreet;

	i = 7; //Fountain Plaza
	strcpy_s(((room + i)->name), "Fountain Plaza");
	strcpy_s(((room + i)->description), "A big Plaza stands in front of you. An abandoned Roller coaster can be seen on your right, a Dock far in the North. Another building can be seen on your left with the name north train Station on it.");
	//Exits
	((exit + i)->north) = Dock;
	((exit + i)->south) = UndergroundPassage;
	((exit + i)->east) = RollerCoaster;
	((exit + i)->west) = NTrainStation;

	i = 8; //Roller coaster
	strcpy_s(((room + i)->name), "Roller Coaster");
	strcpy_s(((room + i)->description), "Since the power is off, the old looking Roller coaster wont work.\n");
	//Exits
	((exit + i)->north) = RollerCoaster;
	((exit + i)->south) = RollerCoaster;
	((exit + i)->east) = RollerCoaster;
	((exit + i)->west) = FountainPlaza;

	i = 9; //Dock
	strcpy_s(((room + i)->name), "Dock");
	strcpy_s(((room + i)->description), "A Boat stands in front of you but, it's cabin is locked with a keychain.\n");
	//Exits
	((exit + i)->north) = Dock;
	((exit + i)->south) = FountainPlaza;
	((exit + i)->east) = Dock;
	((exit + i)->west) = Dock;

	i = 10; //Train station
	strcpy_s(((room + i)->name), "South Train Station");
	strcpy_s(((room + i)->description), "This is the south train station. There is a train, but it doesn't seem to work.\n");
	((exit + i)->north) = STrainStation;
	((exit + i)->south) = STrainStation;
	((exit + i)->east) = STrainStation;//If power activated, you can ride the train
	((exit + i)->west) = EntrancePlaza;

	i = 11; //Train Station
	strcpy_s(((room + i)->name), "North Train Station");
	strcpy_s(((room + i)->description), "This is the magestic North train station. Yet no train seems to be coming...\n");
	((exit + i)->north) = NTrainStation;
	((exit + i)->south) = NTrainStation;
	((exit + i)->east) = FountainPlaza;
	((exit + i)->west) = NTrainStation;//If power activated, you can ride the train
}