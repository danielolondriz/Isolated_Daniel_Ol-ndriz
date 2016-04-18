



class Item : public Entity
{
public:
	Room* location;
	bool inventory;
	bool equip;
	bool IsBox;
	bool InBox;

public:
	Item(const char*, const char*, Room*, bool, bool,bool,bool);
	~Item();

};