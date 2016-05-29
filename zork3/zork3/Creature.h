class Creature : public Entity
{
public:
	uint life;
	Room *location;
public:
	Creature(const char* , const char* , Room*, uint, ObjectType);
	~Creature();
	
};