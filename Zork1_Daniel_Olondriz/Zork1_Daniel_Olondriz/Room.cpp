#include<cmath>
#include "Functions.h"
#include<stdio.h>
Room::Room()
{
	
	Room *room = new Room[10];
}
Room::~Room()
{
	delete[] room;
}