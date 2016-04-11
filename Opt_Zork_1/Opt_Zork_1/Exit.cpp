#include "Room.h"
#include "Exit.h"
#include<stdio.h>
#include<stdlib.h>
#include <string.h>

Exit::Exit(Room*origin, Room*dest, dir direction, bool door)
{
	this->origin = origin;
	this->destination = dest;
	this->direction = direction;
	this->Door = door;
	//printf("%s\n", this->origin->name);
}