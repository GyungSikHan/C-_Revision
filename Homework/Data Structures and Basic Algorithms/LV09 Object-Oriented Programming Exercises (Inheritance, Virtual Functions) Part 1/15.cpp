#include <iostream>
using namespace std;

class Item
{
public:
	Item():name{}, price(){}
	Item(const char* name, const int price)
		:price(price)
	{
		strcpy_s(this->name, sizeof(this->name), name);
	}
	virtual ~Item(){}

	virtual void GetInfo() const
	{
		cout << name << " Price:" << price;
	}
protected:
	char name[256];
	int price;
};

class Weapon : public Item
{
public:
	Weapon(const char* name, const int price, const int power)
		:Item(name, price), power(power)
	{
	}
	void GetInfo() const override
	{
		Item::GetInfo();
		cout << " Power: " << power << endl;
	}

	~Weapon() override{}

private:
	int power;
};

class Potion : public Item
{
public:
	Potion(const char* name, const int price, const int Amount)
		:Item(name, price),recovered(Amount)
	{
	}
	void GetInfo() const override
	{
		Item::GetInfo();
		cout << " Recovered: " << recovered << endl;
	}

	~Potion() override{}

private:
	int recovered;
};

int main()
{
	Weapon sword("Iron Sword", 100, 25);
	Potion hp("Health Potion", 50, 30);
	Item* items[] = { &sword, &hp };
	for (int i = 0; i < 2; ++i)
		items[i]->GetInfo();

}