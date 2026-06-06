#include <iostream>

using namespace std;

class Monster
{
public:
	Monster()
		:name{},hp(){}
	virtual void Attack() { cout << "Monster Attack!!" << std::endl; }
protected:
	char name[256];
	int hp;
};

class Goblin : public Monster
{
public:
	Goblin(const char* name, int hp)
	{
		strcpy_s(this->name, sizeof(this->name), name);
		this->hp = hp;
	}
	void Attack() override
	{
		cout << "Throws rock!" << endl;
	}
};

class Orc : public Monster
{
public:
	Orc(const char* name, int hp)
	{
		strcpy_s(this->name, sizeof(this->name), name);
		this->hp = hp;
	}
	void Attack() override
	{
		cout << "swings axe!" << endl;
	}
};

int main()
{
	Goblin g("Goblin", 50); 
	Orc o("Orc", 100);
	Monster* monsters[] = { &g, &o };
	for (int i = 0; i < 2; ++i)
		monsters[i]->Attack();
}