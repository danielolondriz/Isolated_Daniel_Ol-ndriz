class talkingNPC : public Creature
{
public:
	talkingNPC(const char*, const char*, Room*, uint, ObjectType);
	~talkingNPC();
	void Update();
};