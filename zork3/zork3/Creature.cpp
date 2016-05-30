#include "World.h"
//#include "stdio.h"
//#include "stdlib.h"
//#include "conio.h"
//#include <string.h>
//#include <Windows.h>
#define DELAY 1000
#define COMMANDBUFFER 50
Creature::Creature(const char* names, const char* descriptions, Room*locations, uint lifes, ObjectType types) :Entity(names, descriptions, types), location(locations), life(lifes)
{
};
Creature::~Creature()
{};
