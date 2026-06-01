#include <iostream>
using namespace std;

class GameUnit
{
public:
	GameUnit():HP(){}
	virtual ~GameUnit(){}
protected:
	int HP;
};

class Character : public GameUnit
{
public:
	Character(): name{}{}
	~Character() override {}

	virtual void ShowStatus()
	{
		cout << name <<" HP: "<<HP;
	}
protected:
	char name[256];
};

class Warrior : public Character
{
public:
	Warrior(const char* name, const int Power, int HP)
		:Power(Power)
	{
		strcpy_s(this->name, sizeof(this->name), name);
		this->HP = HP;
	}
	~Warrior() override{}

	void ShowStatus() override
	{
		Character::ShowStatus();
		cout << " Power: " << Power << endl;
	}
private:
	int Power;
};

class Wizard : public Character
{
public:
	Wizard(const char* name, const int Power, int HP)
		:Power(Power)
	{
		strcpy_s(this->name, sizeof(this->name), name);
		this->HP = HP;
	}
	~Wizard() override {}

	void ShowStatus() override
	{
		Character::ShowStatus();
		cout << " Power: " << Power << endl;
	}
private:
	int Power;
};

int main()
{
	Warrior w("Gorath", 100, 30);
	Wizard wiz("Azura", 80, 50);
	Character* party[] = { &w, &wiz };
	for (int i = 0; i < 2; ++i)
		party[i]->ShowStatus();

}