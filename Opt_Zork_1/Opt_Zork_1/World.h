#include "Room.h"
#include "Exit.h"
#include "Player.h"


class World
{
public:
	Player* player;
	Exit* exit[22];
	Room *EntrancePlaza;
	Room *MainStreet;
	Room *HauntedHouse;
	Room *Shop;
	Room *EndofStreet;
	Room *FerrisWheel;
	Room *Underground;
	Room *Fountain;
	Room *RollerCoaster;
	Room *Dock;
	Room *STrainStation;
	Room *NTrainStation;


public:
	World();
	~World();
	void createWorld();
	void movement();

	void go(const char*, const Exit*, Player*, const dir)const;
	void look(const char *, const Exit*, Player*, const dir)const;
	void compare(const char*, const char*);



};