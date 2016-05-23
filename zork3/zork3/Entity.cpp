#include "Entity.h"
Entity::Entity(const char* names, const char* descriptions, ObjectType types) :name(names), description(descriptions), type(types)
{	
}
Entity::~Entity()
{
}
void Entity::Update()
{
}