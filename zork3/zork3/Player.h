
class Player : public Creature
{
public:
	Player(const char*, const char*, Room*, uint, ObjectType);
	~Player();
public:
	void Go(const dir)const;
	void look(const dir)const;
	void Open()const;
	void Close(const dir)const;
};