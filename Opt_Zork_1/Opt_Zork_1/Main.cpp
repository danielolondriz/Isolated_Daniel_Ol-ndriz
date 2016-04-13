#include<cmath>
#include<stdio.h>
#include<stdlib.h>
#include "world.h"
int main(){
	Vector <MyString> tokens;
	World world;
	world.createWorld();
	world.movement(tokens);

	getchar();
	return 0;
}