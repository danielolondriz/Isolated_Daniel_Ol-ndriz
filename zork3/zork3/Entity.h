#ifndef __ENTITY_H__
#define __ENTITY_H__
#include "MyString.h"

enum ObjectType{ ROOM, EXIT, CREATURE, ITEM };


class Entity
{
public:
	MyString name;
	MyString description;
	ObjectType type;
public:
	Entity(const char*, const char*, ObjectType);
	virtual ~Entity();
	virtual void Update();
};
#endif