#include<iostream>
using namespace std;

class Item
{
public:
	Item():name{},info{},weight(), num(){}
	Item(const char* name, const char* Info, const float weight, const int num)
	{
		strcpy_s(this->name, sizeof(this->name), name);
		strcpy_s(this->info, sizeof(this->info), Info);
		this->weight = weight;
		this->num = num;
	}
	~Item(){}

	void Print()
	{
		cout << "Item: " << name << " - " << info << " (x" << num << ") | Weight: " << weight << endl;
	}

private:
	char name[256];
	char info[256];
	float weight;
	int num;
};

class Inventory
{
public:
	Inventory():length(),item{}, owner{}{}
	~Inventory(){}

	void AddItem(const Item* item)
	{
		this->item[length] = *item;
		length++;
	}
	void SetOwner(const char* owner)
	{
		strcpy_s(this->owner, sizeof(this->owner), owner);
	}

	void Print()
	{
		cout << "Inventory of: " << owner << endl;
		for (int i = 0; i < length; ++i)
		{
			item[i].Print();
		}
	}
private:
	Item item[100];
	int length;
	char owner[256];
};

int main()
{
	Item item = Item("Potion", "Heals 50HP", 0.5, 5);
	Item item2 = Item("Bomb", "Deals 100 Damage", 1.0, 2);

	Inventory inventory{};
	inventory.SetOwner("Player1");
	inventory.AddItem(&item);
	inventory.AddItem(&item2);
	inventory.Print();

}