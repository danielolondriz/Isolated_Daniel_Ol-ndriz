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

	
	MyString *TheString;
	//MyString *first ;
	//MyString *second = nullptr;


public:
	World();
	~World();
	void createWorld();
	void movement();

	void go( const Vector<Exit*>&, Vector <Player*>&, const dir)const;
	void look(const Vector<Exit*>&, Vector <Player*>&, const dir)const;
	void open(const Vector<Exit*>&, Vector <Player*>&, const dir)const;
	void close(const Vector<Exit*>&, Vector <Player*>&, const dir)const;
	void compare(Vector<MyString>&);



};
#endif