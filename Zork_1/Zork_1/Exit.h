enum dir{north,south,east,west};
class Exit
{
public:
	char name[30];
	char description[300];
	Room* origin;
	Room* destination;
	bool close;
	dir direction;
};