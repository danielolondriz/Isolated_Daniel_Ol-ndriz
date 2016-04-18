#include<cmath>
#include<stdio.h>
#include<stdlib.h>
#include "world.h"
#include "MemLeaks.h"
int main(){
	ReportMemoryLeaks();
	World world;
	world.createWorld();
	world.movement();
	printf("\n\n THANKS FOR PLAYING\n\n");
	getchar();
	return 0;
}