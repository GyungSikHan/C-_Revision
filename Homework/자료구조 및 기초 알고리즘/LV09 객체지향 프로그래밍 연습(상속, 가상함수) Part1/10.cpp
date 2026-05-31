#include <iostream>

using namespace std;

class Payment
{
public:
	Payment() :amount(){}
	virtual void Process()
	{
		cout << "Process" << endl;
	}
protected:
	int amount;
};

class CreditCard : public Payment
{
public:
	CreditCard(int amount)
	{
		this->amount = amount;
	}
	void Process() override
	{
		cout << "Processing credit card payment" << endl;
	}
};

class Cash : public Payment
{
public:
	Cash(int amount)
	{
		this->amount = amount;
	}
	void Process() override
	{
		cout << "Processing cash payment" << endl;
	}
};

int main()
{
	CreditCard cc(10000); 
	Cash cash(5000);
	Payment* payments[] = { &cc, &cash };
	for (int i = 0; i < 2; ++i)
		payments[i]->Process();

}