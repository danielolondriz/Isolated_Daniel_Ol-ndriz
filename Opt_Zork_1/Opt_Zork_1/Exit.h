enum dir{ north, south, east, west };
class Exit : public Entity
{
public:
	
	Room* origin;
	Room* destination;
	bool Door;
	dir direction;
public:
	Exit(Room*, Room*, dir, bool, const char*, const char*);
	~Exit();

};