#include <iostream>

using namespace std;

struct Player
{
	float hp;
	float stamina;
	float damage;
	float shild;
	char name[256]{};
};

struct Monster
{
	float hp;
	char name[256]{};
	float damage;
	float shild;
};
struct NPC
{
	int a;
	char name[256]{};
	float d;
};

int main()
{
	cout << "Player Struct Size " << sizeof(Player) << endl;
	cout << "monostate Struct Size " << sizeof(Monster) << endl;
	cout << "NPC Struct Size " << sizeof(NPC) << endl;
}