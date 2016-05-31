class Creature : public Entity
{
public:
	int life;
	uint damage;
	Room *location;
public:
	Creature(const char* , const char* , Room*, int, uint, ObjectType);
	~Creature();
	
};