#include <iostream>
using namespace std;

class Entity
{
public:
	Entity():HP(100){}
protected:
	int HP;
};

class Combatant
{
public:
	Combatant():AttackPower(), DefencePower() {}
	Combatant(int attackPower, int defencePower) :AttackPower(attackPower), DefencePower(defencePower){}
	virtual void Attack() = 0;
	virtual void Defend() = 0;
	virtual void UseSkill(){}
protected:
	int AttackPower;
	int DefencePower;
};

class Warrior : public Combatant, public Entity
{
public:
	Warrior(int attackPower, int defencePower)
		:Combatant(attackPower, defencePower){}
	void Attack() override
	{
		cout << "검 휘두르기" << endl;
	}
	void Defend() override
	{
		cout << "방패 들기" << endl;
	}
	void UseSkill() override
	{
		cout << "회전 배기" << endl;
	}
};

class Mage : public Combatant, public Entity
{
public:
	Mage(int attackPower, int defencePower)
		:Combatant(attackPower, defencePower) {}
	void Attack() override
	{
		cout << "지팡이 휘두르기" << endl;
	}
	void Defend() override
	{
		cout << "배리어 사용" << endl;
	}
	void UseSkill() override
	{
		cout << "썬더 볼트" << endl;
	}
};

class Archer : public Combatant, public Entity
{
public:
	Archer(int attackPower, int defencePower)
		:Combatant(attackPower, defencePower) {}
	void Attack() override
	{
		cout << "화살 쏘기" << endl;
	}
	void Defend() override
	{
		cout << "구르기" << endl;
	}
	void UseSkill() override
	{
		cout << "연속 화살 쏘기" << endl;
	}
};


int main()
{
	Warrior w(100, 30); Mage m(80, 50); Archer a(90, 25);
	Combatant* units[] = { &w, &m, &a };
	for (int i = 0; i < 3; ++i) {
		units[i]->Attack();
		units[i]->Defend();
	}
}