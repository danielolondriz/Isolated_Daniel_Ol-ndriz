#ifndef __WORLD_H__
#define __WORLD_H__

#include"Entity.h"
#include"Room.h"
#include"Player.h"
#include"Exit.h"
#include "Item.h"
#include "Creature.h"
#include "Vector.h"

class World
{
public:
	Vector<Entity*> entities;
public: 
	World();
	void CreateWorld();
	void movement();
};




#endif