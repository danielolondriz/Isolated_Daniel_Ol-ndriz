
class SellerNPC : public Creature
{
public:
	State Tstate;
	DList<Entity*> SList;
public:
	SellerNPC(const char*, const char*, Room*, uint, uint, ObjectType);
	~SellerNPC();
	void Update();
	
};