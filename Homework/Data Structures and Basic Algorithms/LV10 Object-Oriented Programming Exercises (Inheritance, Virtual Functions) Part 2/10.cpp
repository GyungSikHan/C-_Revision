#include <iostream>
using namespace std;

class Beverage
{
public:
	Beverage():price(){}
	virtual ~Beverage(){}
	virtual int GetCost() = 0;

protected:
	int price;
};

class Coffee : public Beverage
{
public:
	Coffee() { price = 2000; }
	~Coffee() override{}
	int GetCost() override
	{
		return price;
	}
};

class AddOn : public Beverage
{
public:
	AddOn(Beverage* beverage)
		: beverage(beverage)
	{
	}
protected:
	Beverage* beverage;
};

class Milk : public AddOn
{
public:
	Milk(Beverage* beverage) :AddOn(beverage) { price = 500; }
	int GetCost() override
	{
		return beverage->GetCost() + price;
	}
	~Milk() override{}
};

int main()
{
	Coffee coffee;
	Milk milkCoffee(&coffee);
	Beverage* drinks[] = { &coffee, &milkCoffee };
	for (int i = 0; i < 2; ++i)
		std::cout << drinks[i]->GetCost() << std::endl;
}