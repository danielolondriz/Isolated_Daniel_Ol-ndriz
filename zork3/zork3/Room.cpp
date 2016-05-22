
#include "World.h"


Room::Room(const char* names, const char* descriptions, bool ligths, bool opens, ObjectType types) : Entity(names, descriptions,types), light(ligths), lightopen(opens)
{

}
Room::~Room(){}