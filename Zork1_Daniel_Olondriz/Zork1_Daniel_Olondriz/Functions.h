class Room
{
public:
	char name[20];
	char description[250];
	Room *room = nullptr;

	Room();
	~Room();
};