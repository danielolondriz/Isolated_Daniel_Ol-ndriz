#include "Dlist.h"
class Player : public Creature
{
public:
	uint money;
	uint maxcap;
	uint maxeq;
	uint elementsinv;
	uint elementseq;
public:
	Player(const char*, const char*, Room*, uint, uint,uint, ObjectType);
	~Player();
public:
	void Go(const dir)const;
	void look(const dir)const;
	void Open()const;
	void Close()const;
	void Pick(Vector<MyString>&);
	void Drop(Vector<MyString>&);
	void Equip(Vector<MyString>&);
	void Unequip(Vector<MyString>&);
	void Put(Vector<MyString>&);
	void Get(Vector<MyString>&);
	void buy(Vector<MyString>&);
	void sell(Vector<MyString>&);
	void attack(Vector<MyString>&);
};