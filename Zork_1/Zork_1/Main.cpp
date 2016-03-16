#include<cmath>
#include<stdio.h>
#include<stdlib.h>
#include "World.h"


int main(){
	//CREATES WORLD
	World world;
	world.createWorld();
	//INTRODUCTION
	system("color 0c");
	printf("\n\n\n\t \t \t \t  THE HUNT\n");
	printf("\n\n\n\t  \t \t  by Daniel Olondriz\n\n\n\n\n");
	
	system("pause");
	system("cls");
	printf("You are in an abandoned theme park following a murderer. \n\n\n\n\n\t\t\t Good Luck! \n\n\n");
	//START MOVING
	world.movement();
	
	
	system("pause");
	return 0;
}