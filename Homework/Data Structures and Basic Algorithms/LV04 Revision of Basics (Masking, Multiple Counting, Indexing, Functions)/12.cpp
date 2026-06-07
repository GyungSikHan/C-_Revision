#include<iostream>
using namespace std;

class Player
{
public:
    Player(): name{}, hp(), attackpoint() {}
    ~Player(){}

    virtual void SetName(const char* name)
    {
        strcpy_s(this->name, sizeof(this->name), name);
    }

    virtual void SetHP(int amount)
    {
        hp = amount;
    }
    virtual void SetAttackPoint(int amount)
    {
        attackpoint = amount;
    }
    virtual const char* GetName() const 
    {
        return name;
    }
    virtual int GetHP() const
    {
        return hp;
    }
    virtual int GetAttackPoint() const
    {
        return attackpoint;
    }

    virtual void PrinttInfo()
    {
        cout<<name<<" : HP ("<< hp<<") Att ("<<attackpoint<<")"<<endl;
    }
protected:
    char name[256];
    int hp;
    int attackpoint;
};

class Warrior : public Player 
{
public:
    Warrior(){cout<<"Warrior"<<endl;}
    ~Warrior(){}
};

class Magicion : public Player 
{
public:
    Magicion(){cout<<"Magicion"<<endl;}
    ~Magicion(){}
};

class Archer : public Player 
{
public:
    Archer(){cout<<"Archer"<<endl;}
    ~Archer(){}
};

class Party
{
public:
    Party(): warrior{}, magition{}, archer{} {}
    ~Party(){}

    void AddWarrior(Player* player)
    {
        warrior = player;
    }
    void AddMagition(Player* player)
    {
        magition = player;
    }
    void AddArcher(Player* player)
    {
        archer = player;
    }

    Player* GetWarrior() const
    {
        return warrior;
    }
    Player* GetMagition() const
    {
        return magition;
    }
    Player* GetArcher() const
    {
        return archer;
    }
    
private:
    Player* warrior;
    Player* magition;
    Player* archer;

};

int main()
{
    Party party{};

    Warrior w; 
    w.SetName("Warrior");
    w.SetHP(100);
    w.SetAttackPoint(20);

    Magicion m;
    m.SetName("Magition");
    m.SetHP(100);
    m.SetAttackPoint(30);

    Archer a;
    a.SetName("Archer");
    a.SetHP(100);
    a.SetAttackPoint(10);

    party.AddWarrior(&w);
    party.AddMagition(&m);
    party.AddArcher(&a);

    party.GetWarrior()->PrinttInfo();
    party.GetMagition()->PrinttInfo();
    party.GetArcher()->PrinttInfo();
}