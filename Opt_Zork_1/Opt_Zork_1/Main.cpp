#include<cmath>
#include<stdio.h>
#include<stdlib.h>
#include "world.h"
#include "MemLeaks.h"
int main(){
	system("color 0D");
	printf("\n\n\n\tWELCOME to ISOLATED\n\n");
	printf("\n\n\n\tBy Daniel Olondriz\n\n\n\n\n");

	system("pause");
	system("cls");
	ReportMemoryLeaks();
	World world;
	world.createWorld();
	world.movement();
	printf("\n\n THANKS FOR PLAYING\n\n");
	
	getchar();
	return 0;
}