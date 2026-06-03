#include <iostream>
using namespace std;

class Skill
{
public:
	Skill():colldown(),skillName{}{}
	virtual void Execute() = 0;
	virtual int GetCooldown() = 0;
	~Skill(){}

protected:
	char skillName[256];
	int colldown;
};

class AttackSkill : public Skill
{
public:
	AttackSkill(const char* name, int colldown)
	{
		strcpy_s(this->skillName, sizeof(this->skillName), name);
		this->colldown = colldown;
	}
	void Execute() override
	{
		cout << skillName << "시전!!" << endl;
	}
	int GetCooldown() override
	{
		return colldown;
	}
	~AttackSkill(){}
};

class DefenceSkill: public Skill
{
public:
	DefenceSkill(const char* name, int colldown)
	{
		strcpy_s(this->skillName, sizeof(this->skillName), name);
		this->colldown = colldown;
	}
	void Execute() override
	{
		cout << skillName << "시전!!" << endl;
	}
	int GetCooldown() override
	{
		return colldown;
	}
	~DefenceSkill(){}
};

class HealSkill : public Skill
{
public:
	HealSkill(const char* name, int colldown)
	{
		strcpy_s(this->skillName, sizeof(this->skillName), name);
		this->colldown = colldown;
	}
	void Execute() override
	{
		cout << skillName << "시전!!" << endl;
	}
	int GetCooldown() override
	{
		return colldown;
	}
	~HealSkill(){}
};

int main()
{
	AttackSkill fireball("fireball", 5);
	DefenceSkill shield("Shield", 10);
	HealSkill heal("Heal", 8);

	Skill* skills[]{ &fireball, &shield,&heal };
	for (int i = 0; i < 3; ++i)
	{
		skills[i]->Execute();
		cout << "Colldown: " << skills[i]->GetCooldown() << endl;
	}
}