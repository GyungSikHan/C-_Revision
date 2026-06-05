#include<iostream>
using namespace std;

class Beverage
{
public:
	Beverage():cost(),description{}{}
	Beverage(int cost, const char* description):cost(cost)
	{
		strcpy_s(this->description, sizeof(this->description), description);
	}
	virtual ~Beverage(){}
	virtual int GetCost()
	{
		return cost;
	}
	virtual char* GetDescription()
	{
		return description;
	}

protected:
	int cost;
	char description[256];
};

class Coffee : public Beverage
{
public:
	Coffee():Beverage(2000, "Coffee"){}
	~Coffee() override{}
};

class Tea : public Beverage
{
public:
	Tea() :Beverage(1000, "Tea") {}
	~Tea() override{}
};

class CondimentDecorator : public Beverage
{
public:
	CondimentDecorator():beverage(){}
	CondimentDecorator(Beverage* beverage):beverage(beverage){}
	~CondimentDecorator() override{}
	
protected:
	Beverage* beverage;
};

class Milk : public CondimentDecorator
{
public:
	Milk(){}
	Milk(Beverage* beverage): CondimentDecorator(beverage)
	{
		
	}
	int GetCost() override
	{
		return beverage->GetCost() + 500;
	}
	char* GetDescription() override
	{
		strcpy_s(description, sizeof(description), beverage->GetDescription());
		strcat_s(description, sizeof(description), "Milk");
		return description;
	}
	~Milk() override{}
};

class Sugar : public CondimentDecorator
{
public:
	Sugar() {}
	Sugar(Beverage* beverage) : CondimentDecorator(beverage)
	{

	}
	int GetCost() override
	{
		return beverage->GetCost() + 300;
	}
	char* GetDescription() override
	{
		strcpy_s(description, sizeof(description), beverage->GetDescription());
		strcat_s(description, sizeof(description), "Sugar");
		return description;
	}
	~Sugar() override {}
};

class Whip : public CondimentDecorator
{
public:
	Whip() {}
	Whip(Beverage* beverage) : CondimentDecorator(beverage)
	{

	}
	int GetCost() override
	{
		return beverage->GetCost() + 400;
	}
	char* GetDescription() override
	{
		strcpy_s(description, sizeof(description), beverage->GetDescription());
		strcat_s(description, sizeof(description), "Sugar");
		return description;
	}
	~Whip() override {}
};


int main()
{
	Coffee coffee;
	Milk milkCoffee(&coffee);
	Sugar sweetMilkCoffee(&milkCoffee);
	Whip fancyCoffee(&sweetMilkCoffee);
	Beverage* drinks[] = { &coffee, &milkCoffee, &sweetMilkCoffee, &fancyCoffee };
	for (int i = 0; i <4 ; ++i)
	{
		std::cout << drinks[i]->GetDescription() << ": " << drinks[i]->GetCost() << std::endl;
	}
}