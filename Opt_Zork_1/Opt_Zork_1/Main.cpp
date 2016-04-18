#include<cmath>
#include<stdio.h>
#include<stdlib.h>
#include "world.h"
int main(){
	
	World world;
	world.createWorld();
	world.movement();
	printf("\n\n THANKS FOR PLAYING\n\n");
	getchar();
	return 0;
}