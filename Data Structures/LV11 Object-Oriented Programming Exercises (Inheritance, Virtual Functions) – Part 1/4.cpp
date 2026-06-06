#include <iostream>
#include <algorithm>

using namespace std;

class Beverage
{
public:
	Beverage(){}
	virtual int GetCost() = 0;
	virtual string GetDescription() = 0;
	virtual ~Beverage(){}
};

class Coffee : public Beverage
{
public:
	Coffee() {}
	int GetCost() override
	{
		return 2000;
	}
	string GetDescription() override
	{
		return "Coffee";
	}
	~Coffee() override {}
};

class AddOn:public Beverage
{
public: 
	AddOn(Beverage* b)
		: beverage(b)
	{}

protected:
	Beverage* beverage;
};

class Milk : public AddOn
{
public:
	Milk(Beverage* b)
		:AddOn(b)
	{
		
	}

	int GetCost() override
	{
		return beverage->GetCost() + 500;
	}
	string GetDescription() override
	{
		return beverage->GetDescription() + " + Milk";
	}
	~Milk() override{}
};

int main()
{
	Coffee* myCoffee = new Coffee();
	cout << myCoffee->GetDescription() << " costs " << myCoffee->GetCost() << " won." << endl;
	Beverage* myCoffeeWithMilk = new Milk(myCoffee);
	cout << myCoffeeWithMilk->GetDescription() << " costs " << myCoffeeWithMilk->GetCost() << " won." << endl;

	delete myCoffee;
	myCoffee = nullptr;
	delete myCoffeeWithMilk;
	myCoffeeWithMilk = nullptr;
}