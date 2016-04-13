#include "Room.h"
#include "Exit.h"
#include "Player.h"
#include "MyString.h"

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
	MyString *TheString;
	MyString *first ;
	MyString *second = nullptr;


public:
	World();
	~World();
	void createWorld();
	void movement();

	void go(const MyString*, const Exit*, Player*, const dir)const;
	void look(const char *, const Exit*, Player*, const dir)const;
	void compare(const MyString*, const MyString*);



};