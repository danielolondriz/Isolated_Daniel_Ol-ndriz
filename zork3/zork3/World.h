#ifndef __WORLD_H__
#define __WORLD_H__

#include"Entity.h"
#include"Room.h"
#include"Exit.h"
#include "Creature.h"
#include"Player.h"

#include "Item.h"
#include "talkingNPC.h"

#include "Vector.h"


class World
{
public:
	Vector<Entity*> entities;
	Player* ThePlayer;
public: 
	World();
	void CreateWorld();
	void movement();
};

extern World *world;


#endif