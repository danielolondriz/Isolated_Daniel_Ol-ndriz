#include "World.h"


Item::Item(const char* name, const char* description, Room* locations, bool inventorys, bool equips, bool Isbox, bool inbox, ObjectType types) : Entity(name, description, types), location(locations), inventory(inventorys), equip(equips), InBox(inbox), IsBox(Isbox)
{
}
Item:: ~Item()
{}