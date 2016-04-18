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
	void equip(const Vector <Player*>&, Vector<Item*>&, Vector<MyString>&, unsigned int&)const;
	void unequip(const Vector <Player*>&, Vector<Item*>&, Vector<MyString>&, unsigned int&)const;
	void ligth(const Vector < Room*>&);
	void unligth(const Vector < Room*>&);
	void travel(Vector <Player*>&, const Vector <Room*>&, Vector<Item*>&);
	void inventory(Vector<Item*>&);
	void compare(Vector<MyString>&,unsigned int&, unsigned int&);



};
#endif