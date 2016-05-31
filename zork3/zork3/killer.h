enum KState{ IDLE, FIGHT, DEAD, DISAPPEAR };
class Killer : public Creature
{
public:
	KState Killstate;
public:
	Killer(const char*, const char*, Room*, int, uint, ObjectType);
	~Killer();
	void Update();
	void Fight();
};