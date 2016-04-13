#ifndef __ROOM_H__
#define __ROOM_H__


class Room
{
public:
	const char* name = nullptr;
	const char* description = nullptr;
public:

	Room(const char *, const char*);
	~Room();
};
#endif