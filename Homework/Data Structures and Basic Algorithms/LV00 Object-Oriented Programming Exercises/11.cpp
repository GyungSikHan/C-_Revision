#include<iostream>
using namespace std;

class BankAccount
{
public:
	BankAccount():name{}, balance(), account{},type{}, deposit(){}
	BankAccount(const char* name, int balance, const char* account, const char* type, int deposit)
		:balance(balance), deposit(deposit)
	{
		strcpy_s(this->name, sizeof(this->name), name);
		strcpy_s(this->account, sizeof(this->account), account);
		strcpy_s(this->type, sizeof(this->type), type);
	}
	~BankAccount(){}
	
	int CalculationBalance()
	{
		balance += deposit;
		return balance;
	}
	void Print()
	{
		cout << "Account: " << account << " | Bank: " << name << " | Type: " << type << endl;
		cout << "Balance: $" << balance << " -> Deposit $" << deposit << " -> Balance: $" << CalculationBalance() << endl;
	}
private:
	char name[256];
	int balance;
	char account[256];
	char type[256];
	int deposit;
};

class Customer
{
public:
	Customer():name{}, phone{}, address{}, age(){}
	Customer(const char* name, const char* phone, const char* address, const int age)
		:age(age)
	{
		strcpy_s(this->name, sizeof(this->name), name);
		strcpy_s(this->phone, sizeof(this->phone), phone);
		strcpy_s(this->address, sizeof(this->address), address);
	}
	~Customer(){}

	void SetBankAccount(BankAccount* bankAccount)
	{
		this->bankAccount = *bankAccount;
	}

	void Print()
	{
		cout << "Custommer: " << name << " | Phone: " << phone << " | Age: " << age << endl;
		bankAccount.Print();
	}

private:
	char name[256];
	char phone[256];
	char address[256];
	int age;

	BankAccount bankAccount;
};

int main()
{
	Customer custommer = Customer("Alice", "010-1234-5678", "Newyok", 28);
	BankAccount bank = BankAccount("Hana", 1500, "123-456", "Saving", 200);
	
	custommer.SetBankAccount(&bank);

	custommer.Print();
}