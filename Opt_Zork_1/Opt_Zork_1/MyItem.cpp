#include "World.h"


Item::Item(const char* name, const char* description, Room* locations, bool inventorys, bool equips) : Entity(name, description), location(locations), inventory(inventorys), equip(equips)
{
	
}
Item:: ~Item()
{

}