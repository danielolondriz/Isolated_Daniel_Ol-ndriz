#include "World.h"
#include<stdio.h>
#include<cmath>
#include <string.h>

void Movement(World *world)
{
	char answer[20];
	int i = 0;

	char *Counter;
	char *first;
	char *second;
	//actions
	char *look = "look";
	char *go = "go";
	char *help = "help";
	char *quit = "quit";
	char *north = "north";

	//Asks for the action
	printf("What do you want to do?\n");
	gets_s(answer);

	//printf("You are IN the %s\n", world->room->name);
	//with strtok it takes the first and the second word
	first = strtok_s(answer, " ", &Counter);
	second = strtok_s(NULL, " ", &Counter);
	//North
	if (*first == *north)
	{
		if ((world->exit + i)->north == i)
		{
			printf("There is a Wall\n");
		}
		else 
		{
			i = (world->exit + i)->north;
			printf("You are now in the %s\n", ((world->room + i)->name));
		}
		
	}

	printf("%s\n", first);
	printf("%s\n", second);
}