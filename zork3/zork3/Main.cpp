#include<cmath>
//#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>

#include "World.h"
#include "MemLeaks.h"
World *world = nullptr;
int main()
{
	world = new World();
	//world->CreateWorld();
	//world.CreateWorld();
	world->movement();
	return 0;
}