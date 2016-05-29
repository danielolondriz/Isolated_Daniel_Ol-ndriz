#include "World.h"
talkingNPC::talkingNPC(const char* names, const char*des, Room* loc, uint li, ObjectType ty) :Creature(names, des, loc, li, ty)
{}
talkingNPC::~talkingNPC()
{}

void talkingNPC::Update()
{
	printf("Hy.\n");
}