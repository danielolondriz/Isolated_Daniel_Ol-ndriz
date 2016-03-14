#include "Room.h"
#include "Exits.h"
class World
{
public:
	Room *room = nullptr;
	Exit *exit = nullptr;
public:
	World();
	~World();
	void createWorld();
	
	

	
};