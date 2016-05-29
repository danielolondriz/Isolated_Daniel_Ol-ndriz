
#include "World.h"
#include "stdio.h"
Player::Player(const char* names, const char*des, Room* loc, uint life, ObjectType ty) :Creature(names,des, loc, life,ty)
{

}
Player::~Player(){};