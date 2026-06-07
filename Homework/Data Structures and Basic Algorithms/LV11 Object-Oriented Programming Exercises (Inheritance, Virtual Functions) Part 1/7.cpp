#include <iostream>
using namespace std;

class Unit
{
public:
	virtual void Move(){}
protected:
	char name[256];
};

class Warrior : public Unit
{
public:
	Warrior(const char* name)
	{
		strcpy_s(this->name, sizeof(this->name), name);
	}
	void Move() override
	{
		cout << name << " Move" << endl;
	}
};

class Archer : public Unit
{
public:
	Archer(const char* name)
	{
		strcpy_s(this->name, sizeof(this->name), name);
	}
	void Move() override
	{
		cout << name << " Move" << endl;
	}
};

int main()
{
	Warrior w("Thor"); 
	Archer a("Robin");
	Unit* units[] = { &w, &a };
	for (int i = 0; i < 2; ++i)
		units[i]->Move();
}