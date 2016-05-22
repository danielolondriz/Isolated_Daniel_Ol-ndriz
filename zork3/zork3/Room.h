#ifndef __ROOM_H__
#define __ROOM_H__
//#include "Entity.h"

//class MyString;
class Room : public Entity
{
public:
	bool light;
	bool lightopen;

public:

	Room(const char *, const char*, bool, bool, ObjectType);
	~Room();
};
#endif