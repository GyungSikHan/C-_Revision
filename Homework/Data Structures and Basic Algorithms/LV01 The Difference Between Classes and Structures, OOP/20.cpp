#include<iostream>
using namespace std;

struct Name
{
    char Name[20];
};

struct Point
{
    int y;
    int x;
};

struct PlayerInfo
 {
    Name name;
    Point position;
 };

class Weapon
{
public:
    Weapon(): weaponName{} {}
    ~Weapon(){}
    void SetWeaponName(Name* name)
    {
        memcpy(&weaponName, name, sizeof(weaponName));
    }
    Name GetWeaponName() const
    {
        return weaponName;
    }

    void PrintInfo()
    {
        cout<<"weapon : "<<weaponName.Name<<endl;
    }
private:
    Name weaponName;
};

class Player
{
public:
    Player(): playerInfo{}, myWeapon{}, hp(0.0f) {}
    Player(const PlayerInfo* info, const Weapon* weapon, const float initHP)
    : hp(initHP)
    {
        memcpy(&playerInfo, info, sizeof(playerInfo));
        memcpy(&myWeapon, weapon, sizeof(myWeapon));
    }
    ~Player(){}

    void PrintInfo()
    {
        cout << playerInfo.name.Name<<endl;
        cout<< "Position: y = "<<playerInfo.position.y<<", x = "<<playerInfo.position.x<<endl;
        cout<<"hp : "<<hp<<endl;
        myWeapon.PrintInfo();
    }

private:
    PlayerInfo playerInfo;
    Weapon myWeapon;
    float hp;
};

int main()
{
    Name swrodName{"sword"};
    Weapon sword;
    sword.SetWeaponName(&swrodName);

    Name warriorName{"warrior"};
    Point warriorPosition{1,2};
    PlayerInfo warriorInfo{warriorName, warriorPosition};
    
    Player warrior = Player(&warriorInfo, &sword, 200);

    Name bowName{"bow"};
    Weapon bow;
    bow.SetWeaponName(&bowName);

    Name archerName{"archer"};
    Point archerPosition{2,3};
    PlayerInfo archerInfo{archerName, archerPosition};
    
    Player archer = Player(&archerInfo, &bow, 100);

    warrior.PrintInfo();
    archer.PrintInfo();
}