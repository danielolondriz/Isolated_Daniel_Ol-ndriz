



class Item : public Entity
{
public:
	Room* location;
	bool inventory;
	bool equip;
public:
	Item(const char*, const char*, Room*, bool, bool);
	~Item();

};