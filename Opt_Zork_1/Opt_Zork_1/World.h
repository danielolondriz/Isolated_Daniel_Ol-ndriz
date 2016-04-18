#ifndef __WORLD_H__
#define __WORLD_H__
#include "Room.h"
#include "Exit.h"
#include "Player.h"
#include "Entity.h"
#include "MyItem.h"
//#include "MyString.h"
#include "Vector.h"

class World
{
public:
	Vector <Player*> player;
	Vector<Exit*> exit;
	Vector <Room*> rooms;
	Vector <Item*> items;

	
	MyString *TheString;
	//MyString *first ;
	//MyString *second = nullptr;


public:
	World();
	~World();
	void createWorld();
	void movement();

	void go (const dir)const;
	void look( const dir)const;
	void lookItem( Vector<MyString>&);
	void open( const dir)const;
	void close( const dir)const;
	void take(  Vector<MyString>&, unsigned int&)const;
	void drop(Vector<MyString>&, unsigned int&)const;
	void equip( Vector<MyString>&, unsigned int&)const;
	void unequip( Vector<MyString>&, unsigned int&)const;
	void put(Vector<MyString>&, unsigned int&, unsigned int&);
	void get(Vector<MyString>&, unsigned int&, unsigned int&);
	void ligth();
	void unligth();
	void travel();
	void inventory(Vector<Item*>&);
	void compare(Vector<MyString>&, unsigned int&, unsigned int&, unsigned int&);



};
#endif