#include "Dlist.h"
enum State{ MOVING, TALKING  };
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
	
	void respond();
};