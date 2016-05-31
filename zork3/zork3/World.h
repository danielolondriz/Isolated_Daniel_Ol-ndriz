#ifndef __WORLD_H__
#define __WORLD_H__

#include"Entity.h"
#include"Room.h"
#include"Exit.h"
#include "Creature.h"
#include"Player.h"

#include "Item.h"
#include "talkingNPC.h"
#include "SellerNPC.h"
#include "killer.h"

#include "Vector.h"
#include "Dlist.h"



class World
{
public:
	Vector<Entity*> entities;
	Vector <MyString> words;
	MyString temporal;
	Player* ThePlayer;
	talkingNPC *talker = nullptr;
	SellerNPC *TheSeller = nullptr;
	Killer *TheKiller = nullptr;
	int cooldown = 0;
public: 
	World();
	void CreateWorld();
	void movement();
	void printItems();
	void printShop();
	void printinv();
};

extern World *world;


#endif