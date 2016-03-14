#include<cmath>
#include<stdio.h>
#include<stdlib.h>
#include "World.h"
#include "Functions.h"

int main(){
	World world;
	world.createWorld();
	
	printf("You are %s\n", world.room->name);
	//world.player->Movement(&world);
	Movement(&world);
	system("pause");
	return 0;
}