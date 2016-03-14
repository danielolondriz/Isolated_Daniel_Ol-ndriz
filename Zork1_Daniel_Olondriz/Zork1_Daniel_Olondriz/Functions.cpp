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
	//directions
	char *north = "north";
	char *south = "south";
	char *east = "east";
	char *west = "west";
	char *n = "n";
	char *s = "s";
	char *e = "e";
	char *w = "w";

	//Asks for the action
	do{
		printf("What do you want to do?\n");
		gets_s(answer);
	} while (answer==NULL);
	
	//with strtok it takes the first and the second word
	first = strtok_s(answer, " ", &Counter);
	second = strtok_s(NULL, " ", &Counter);
	//ONE WORD
	//North
	if (*first == *north || *first == *n)
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
	//South
	if (*first == *south || *first == *s)
	{
		if ((world->exit + i)->south == i)
		{
			printf("There is a Wall\n");
		}
		else
		{
			i = (world->exit + i)->south;
			printf("You are now in the %s\n", ((world->room + i)->name));
		}

	}
	//east
	if (*first == *east || *first == *e)
	{
		if ((world->exit + i)->east == i)
		{
			printf("There is a Wall\n");
		}
		else
		{
			i = (world->exit + i)->east;
			printf("You are now in the %s\n", ((world->room + i)->name));
		}

	}
	//west
	if (*first == *west || *first == *w)
	{
		if ((world->exit + i)->west == i)
		{
			printf("There is a Wall\n");
		}
		else
		{
			i = (world->exit + i)->west;
			printf("You are now in the %s\n", ((world->room + i)->name));
		}

	}
	//TWO WORD
	//GO
	if (*first == *go)
	{
		//North
		if (*second == *north || *first == *n)
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
		//South
		if (*second == *south || *first == *s)
		{
			if ((world->exit + i)->south == i)
			{
				printf("There is a Wall\n");
			}
			else
			{
				i = (world->exit + i)->south;
				printf("You are now in the %s\n", ((world->room + i)->name));
			}

		}
		//east
		if (*second == *east || *first == *e)
		{
			if ((world->exit + i)->east == i)
			{
				printf("There is a Wall\n");
			}
			else
			{
				i = (world->exit + i)->east;
				printf("You are now in the %s\n", ((world->room + i)->name));
			}

		}
		//west
		if (*second == *west || *first == *w)
		{
			if ((world->exit + i)->west == i)
			{
				printf("There is a Wall\n");
			}
			else
			{
				i = (world->exit + i)->west;
				printf("You are now in the %s\n", ((world->room + i)->name));
			}

		}
	}
	//TWO WORD
	//LOOk
	if (*first == *look)
	{
		//North
		if (*second == *north || *first == *n)
		{
			if ((world->exit + i)->north == i)
			{
				printf("There is a Wall\n");
			}
			else
			{
				i = (world->exit + i)->north;
				printf("You are now in the %s\n", ((world->room + i)->description));
			}

		}
		//South
		if (*second == *south || *first == *s)
		{
			if ((world->exit + i)->south == i)
			{
				printf("There is a Wall\n");
			}
			else
			{
				i = (world->exit + i)->south;
				printf("You are now in the %s\n", ((world->room + i)->description));
			}

		}
		//east
		if (*second == *east || *first == *e)
		{
			if ((world->exit + i)->east == i)
			{
				printf("There is a Wall\n");
			}
			else
			{
				i = (world->exit + i)->east;
				printf("You are now in the %s\n", ((world->room + i)->description));
			}

		}
		//west
		if (*second == *west || *first == *w)
		{
			if ((world->exit + i)->west == i)
			{
				printf("There is a Wall\n");
			}
			else
			{
				i = (world->exit + i)->west;
				printf("You are now in the %s\n", ((world->room + i)->description));
			}

		}
	}
	printf("%s\n", first);
	printf("%s\n", second);
}