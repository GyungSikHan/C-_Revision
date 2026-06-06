#include <iostream>
using namespace std;

class Skill
{
public:
	Skill() : skillName{}, coolDown() {}
	Skill(const char* name, int amount)
	: coolDown(amount)
	{
		strcpy_s(skillName, sizeof(skillName), name);
	}
	virtual ~Skill(){}
	virtual void Execute() = 0;
	virtual int GetCooldown() const = 0;

protected:
	char skillName[256];
	int coolDown;
};

class AttackSkill : public Skill
{
public:
	AttackSkill(const char* name, int amount):Skill(name, amount){}
	~AttackSkill()override{}
	void Execute() override
	{
		cout << skillName << " 시전!!" << endl;
	}

	int GetCooldown() const override
	{
		return coolDown;
	}
};

class DefenseSkill : public Skill
{
public:
	DefenseSkill(const char* name, int amount) :Skill(name, amount) {}
	~DefenseSkill()override {}
	void Execute() override
	{
		cout << skillName << " 시전!!" << endl;
	}
	int GetCooldown() const override
	{
		return coolDown;
	}
};

class HealSkill : public Skill
{
public:
	HealSkill(const char* name, int amount) :Skill(name, amount) {}
	~HealSkill()override {}
	void Execute() override
	{
		cout << skillName << " 시전!!" << endl;
	}
	int GetCooldown() const override
	{
		return coolDown;
	}
};

int main()
{
	AttackSkill fireball("Fireball", 5);
	DefenseSkill shield("Shield", 10);
	HealSkill heal("Heal", 8);
	Skill* skills[] = { &fireball, &shield, &heal };
	for (int i = 0; i < 3; ++i) {
		skills[i]->Execute();
		std::cout << "Cooldown: " << skills[i]->GetCooldown() << std::endl;
	}
}