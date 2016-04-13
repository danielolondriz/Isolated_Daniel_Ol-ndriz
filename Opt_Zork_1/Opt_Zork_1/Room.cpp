//#include "Room.h"
#include "World.h"
//#include "Exit.h"
#include<stdio.h>
#include<stdlib.h>




Room::Room(const char* names, const char* descriptions) : Entity(names, descriptions)
{
	/*
	int len1 = strlen(name) + 1;
	int len2 = strlen(description) + 1;
	this->name = new char[len1];
	this->description = new char[len2];
	strcpy_s(this->name, len1, name);
	strcpy_s(this->description, len2, description);
	*/
	
}
Room::~Room()
{
	
}
