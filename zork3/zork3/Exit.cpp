//#include "Room.h"
//#include "Exit.h"
#include "World.h"



Exit::Exit(Room*origins, Room*dest, dir directions, bool hasdoor, bool opens, const char* names, const char* descriptions, ObjectType types) : Entity(names, descriptions, types), origin(origins), destination(dest), direction(directions), hasDoor(hasdoor), open(opens)
{
}
Exit::~Exit()
{}