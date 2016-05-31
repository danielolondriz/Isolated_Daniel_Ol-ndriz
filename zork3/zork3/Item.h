



class Item : public Entity
{
public:
	uint price = 0;
public:
	Room* location;
	bool inventory;
	bool equip;
	bool IsBox;
	bool InBox;

public:
	Item(const char*, const char*, Room*, bool, bool, bool, bool, ObjectType,uint);
	~Item();

};