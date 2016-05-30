class talkingNPC : public Creature
{
public:
	talkingNPC(const char*, const char*, Room*, uint, uint, ObjectType);
	~talkingNPC();
	void Update();
};