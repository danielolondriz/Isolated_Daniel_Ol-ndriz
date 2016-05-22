#include "World.h"
#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#include <string.h>
#include <Windows.h>
#define DELAY 1000
#define COMMANDBUFFER 50
Creature::Creature(const char* names, const char* descriptions, Room*locations, uint lifes, ObjectType types) :Entity(names, descriptions, types), location(locations), life(lifes)
{
};
Creature::~Creature()
{};
void Creature::Update()
{
	char command[COMMANDBUFFER];
	bool firsttimeinloop = true;
	unsigned int currenttime = 0;
	unsigned int initialtime = 0;
	unsigned int charcommandnum = 0;
	//timeGetTime()
	initialtime = GetTickCount();

	while (command != "q\0"){
		//Executa el codi cada x milisegons (DELAY)
		currenttime = GetTickCount();
		if (currenttime >= (initialtime + DELAY)){
			printf("Hy.\n");
			initialtime = currenttime;

		}
	}
}