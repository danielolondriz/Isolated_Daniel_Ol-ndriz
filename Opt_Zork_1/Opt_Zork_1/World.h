#ifndef __WORLD_H__
#define __WORLD_H__
#include "Room.h"
#include "Exit.h"
#include "Player.h"
#include "Entity.h"
//#include "MyString.h"
#include "Vector.h"

class World
{
public:
	Vector <Player*> player;
	Vector<Exit*> exit;
	Vector <Room*> rooms;
	/*
	Room *EntrancePlaza;
	Room *MainStreet;
	Room *HauntedHouse;
	Room *Shop;
	Room *EndofStreet;
	Room *FerrisWheel;
	Room *Underground;
	Room *Fountain;
	Room *RollerCoaster;
	Room *Dock;
	Room *STrainStation;
	Room *NTrainStation;*/
	MyString *TheString;
	//MyString *first ;
	//MyString *second = nullptr;


public:
	World();
	~World();
	void createWorld();
	void movement(Vector<MyString> );

	void go(const MyString*,  Vector<Exit*>&, Player*, const dir)const;
	void look(const char *, const Exit*, Player*, const dir)const;
	void compare(const MyString*, const MyString*);



};
#endif