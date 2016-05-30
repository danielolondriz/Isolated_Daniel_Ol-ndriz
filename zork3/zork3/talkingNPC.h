
enum State{ MOVING, TALKING, DEAD, DISAPPEAR };
class talkingNPC : public Creature
{
public:
	State Tstate;
public:
	talkingNPC(const char*, const char*, Room*, uint, uint, ObjectType);
	~talkingNPC();
	void Update();
	void Move();
	void Talk();
	void dead();
	void respond();
};