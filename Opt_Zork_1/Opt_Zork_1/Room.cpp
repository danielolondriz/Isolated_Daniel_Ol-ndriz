#include "Room.h"
#include "Exit.h"
#include<stdio.h>
#include<stdlib.h>
#include "MyString.h"

Room::Room(const char* name, const char* description)
{
	/*
	int len1 = strlen(name) + 1;
	int len2 = strlen(description) + 1;
	this->name = new char[len1];
	this->description = new char[len2];
	strcpy_s(this->name, len1, name);
	strcpy_s(this->description, len2, description);
	*/
	this->name = name;
	this->description = description;
}
Room::~Room()
{
	delete[] name;
	delete[] description;
}
