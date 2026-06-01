#include<iostream>
using namespace std;

class Drink
{
public:
	Drink():name{},price(){}
	Drink(const char* name, const int price)
		: price(price)
	{
		strcpy_s(this->name, sizeof(this->name), name);
	}
	virtual ~Drink(){}
	virtual void Dispense()
	{
		cout << "Dispensing";
	}
protected:
	char name[256];
	int price;
};

class Soda : public Drink
{
public:
	Soda(){}
	Soda(const char* name, const int price)
		:Drink(name, price) {}
	virtual void Dispense() override
	{
		Drink::Dispense();
		cout << " soda with ice" << endl;
	}
};

class Juice : public Drink
{
public:
	Juice() {}
	Juice(const char* name, const int price)
		:Drink(name, price) {}
	virtual void Dispense() override
	{
		Drink::Dispense();
		cout << " fresh juice" << endl;
	}
};

int main()
{
	Soda soda("Coke", 1500); Juice juice("Orange", 2000);
	Drink* drinks[] = { &soda, &juice };
	for (int i = 0; i < 2; ++i)
		drinks[i]->Dispense();

}