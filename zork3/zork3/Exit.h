enum dir{ north, south, east, west };
class Exit : public Entity
{
public:

	Room* origin;
	Room* destination;
	bool hasDoor;
	bool open;
	dir direction;
public:
	Exit(Room*, Room*, dir, bool,bool, const char*, const char*,ObjectType);
	~Exit();

};