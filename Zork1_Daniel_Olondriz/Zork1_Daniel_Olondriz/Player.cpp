//#include "Player.h"
#include "World.h"
#include<stdio.h>
#include<cmath>
#include <string.h>
enum directions {north,south,west,east};
void Player::Movement()
{
	char answer[20];
	

	char *Counter;
	char *first;
	char *second;
	//actions
	char *look = "look";
	char *north = "north";
	
	//Asks for the action
	printf("What do you want to do?\n");
	gets_s(answer);

	//printf("You are in the %s\n", world->room->name);
	//with strtok it takes the first and the second word
	first = strtok_s(answer, " ",&Counter);
	second = strtok_s(NULL, " ", &Counter);
	
	if (*first == *north )
	{
		printf("Its %s\n", first);
	}

	printf("%s\n", first);
	printf("%s\n", second);
}