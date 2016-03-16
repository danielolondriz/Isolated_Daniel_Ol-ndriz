#include "Room.h"
#include "Exit.h"
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
	
		void const movement();
	




};