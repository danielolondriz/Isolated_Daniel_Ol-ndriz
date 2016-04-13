#ifndef __ENTITY_H__
#define __ENTITY_H__
#include "MyString.h"
class Entity
{
public:
	MyString name;
	MyString description;
public:
	Entity(const char*, const char*);
	~Entity();
};
#endif