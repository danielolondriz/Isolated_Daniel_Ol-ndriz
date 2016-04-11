#ifndef __ROOM_H__
#define __ROOM_H__

#include<string.h>
class Room
{
public:
	char* name = nullptr;
	char* description = nullptr;
public:

	Room(const char *, const char*);
	~Room();
};
#endif