#include <iostream>
using namespace std;

class Account
{
public:
	virtual void Deposit(int data) {}
	virtual void Withdraw(int data){}
	virtual void ShowBalance(){}
};

class SavingsAccount: public Account
{
public:
	SavingsAccount(int deposit, float interestrate)
		: deposit(deposit), interestrate(interestrate)
	{
		
	}

	void Deposit(int data) override
	{
		deposit += data;
		cout << deposit << endl;
	}
	void Withdraw(int data) override
	{
		deposit -= data;
		cout << deposit << endl;
	}
	void ShowBalance() override
	{
		cout << deposit << endl;
	}

private:
	int deposit;
	float interestrate;
};

class CheckingAccount:public Account
{
public:
	CheckingAccount(int deposit, float fee)
		:deposit(deposit), fee(fee)
	{
	}
	void Deposit(int data) override
	{
		deposit += data;
		cout << deposit << endl;
	}
	void Withdraw(int data) override
	{
		deposit -= data;
		cout << deposit << endl;
	}
	void ShowBalance() override
	{
		cout << deposit << endl;
	}

private:
	int deposit;
	float fee;
};
int main()
{
	SavingsAccount sa(1000, 0.03f);
	CheckingAccount ca(2000, 1.5f);
	Account* accounts[] ={&sa,&ca};

	for (int i = 0; i < 2; ++i)
	{
		accounts[i]->Deposit(500);
		accounts[i]->Withdraw(200);
		accounts[i]->ShowBalance();
	}
}