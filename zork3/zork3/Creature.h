class Creature : public Entity
{
public:
	uint life;
	uint damage;
	Room *location;
public:
	Creature(const char* , const char* , Room*, uint, uint, ObjectType);
	~Creature();
	
};