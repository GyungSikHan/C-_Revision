#include <iostream>
using namespace std;

class Account
{
public:
	Account(): balance(){}
	Account(int amount)
		:balance(amount)
	{}
	virtual ~Account(){}

	virtual void Deposit(int amount)
	{
		balance += amount;
	}
	virtual void Withdraw(int amount)
	{
		balance -= amount;
	}
	virtual void ShowBalance()
	{
		cout << "Balance: " << balance << endl;
	}

protected:
	int balance;
};

class SavingsAccount : public Account
{
public:
	SavingsAccount(int amount, float interestRate)
		:Account(amount),interestRate(interestRate)
	{}
	~SavingsAccount()override {}

	void Deposit(int amount) override
	{
		Account::Deposit(amount);
	}
	void Withdraw(int amount) override
	{
		Account::Withdraw(amount);
	}
	void ShowBalance() override
	{
		cout << "Savings Account"<<endl;
		Account::ShowBalance();
		cout << "Interest Rate: " << interestRate << endl;
	}

protected:
	float interestRate;
};

class CheckingAccount : public Account
{
public:
	CheckingAccount(int amount, float fee)
		:Account(amount), fee(fee)
	{}
	~CheckingAccount()override {}

	void Deposit(int amount) override
	{
		Account::Deposit(amount);
	}
	void Withdraw(int amount) override
	{
		Account::Withdraw(amount);
	}
	void ShowBalance() override
	{
		cout << "Checking Account"<<endl;
		Account::ShowBalance();
		cout << "Fee: " << fee << endl;
	}

protected:
	float fee;
};

int main()
{
	SavingsAccount sa(1000, 0.03);
	CheckingAccount ca(2000, 1.5);
	Account* accounts[] = { &sa, &ca };
	for (int i = 0; i < 2; ++i) {
		accounts[i]->Deposit(500);
		accounts[i]->Withdraw(200);
		accounts[i]->ShowBalance();
	}

}