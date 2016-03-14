#include "Room.h"
#include "Exits.h"
#include "Player.h"
class World
{
public:
	Room *room = nullptr;
	Exit *exit = nullptr;
	Player *player = nullptr;
public:
	World();
	~World();
	void const createWorld();
	
	

	
};