//#include "Room.h"
//#include "Exit.h"
#include "World.h"
#include<stdio.h>
#include<stdlib.h>


Exit::Exit(Room*origins, Room*dest, dir directions, bool door, const char* names, const char* descriptions) : Entity(names, descriptions), origin(origins), destination(dest), direction(directions), Door(door)
{
	/*origin = origins;
	destination = dest;
	direction = directions;
	Door = door;*/
	
}