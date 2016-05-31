#include "World.h"
SellerNPC::SellerNPC(const char* names, const char*des, Room* loc, uint li, uint dam, ObjectType ty) :Creature(names, des, loc, li, dam, ty)
{
	
}
SellerNPC::~SellerNPC()
{}
void SellerNPC::Update()
{
	for (uint i = 34; i < 39; i++)
	{
		if (((Item*)world->entities[i])->location == world->TheSeller->location && ((Item*)world->entities[i])->inventory == false)
		{
			SList.push_back(((Item*)world->entities[i]));
			printf("\n%s\n", ((Item*)world->entities[i])->name);
			((Item*)world->entities[i])->location = NULL;
		}
	}
}