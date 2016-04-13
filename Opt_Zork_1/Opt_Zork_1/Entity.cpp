#include "Entity.h"
Entity::Entity(const char* names, const char* descriptions)
{
	name = names;
	description = descriptions;
}
Entity::~Entity(){}