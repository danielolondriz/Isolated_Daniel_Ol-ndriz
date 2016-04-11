enum dir{ north, south, east, west };
class Exit
{
public:
	//char* name = nullptr;
	//char* description = nullptr;
	Room* origin;
	Room* destination;
	bool Door;
	dir direction;
public:
	Exit(Room*, Room*, dir, bool);


};