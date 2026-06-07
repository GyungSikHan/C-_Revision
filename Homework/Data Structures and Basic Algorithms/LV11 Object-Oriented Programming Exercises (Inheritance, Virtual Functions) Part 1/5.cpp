#include <iostream> 
using namespace std;

class Character
{
public:
	virtual void Attack(){}
protected:
	char name[256];
};

class Knight : public Character
{
public:
	Knight(const char* name)
	{
		strcpy_s(this->name, sizeof(this->name), name);
	}
	void Attack() override
	{
		cout << "slashes with sword!" << endl;
	}
};

class Mage : public Character
{
public:
	Mage(const char* name)
	{
		strcpy_s(this->name, sizeof(this->name), name);
	}
	void Attack() override
	{
		cout << "casts a spell!" << endl;
	}
};

int main()
{
	Knight k("Arthur"); Mage m2("Merlin");
	Character* party[] = { &k, &m2 };
	for (int i = 0; i < 2; ++i)
		party[i]->Attack();

}