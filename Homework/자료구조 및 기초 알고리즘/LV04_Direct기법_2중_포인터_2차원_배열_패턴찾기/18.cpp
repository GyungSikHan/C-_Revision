#include <iostream>
using namespace std;

class Account
{
public:
	Account()
		:name{},num(),money()
	{}
	Account(const char* name, const int& num, const int& money )
		: name{}, num(num), money(money)
	{
		strcpy_s(this->name, sizeof(this->name), name);
	}
	~Account(){}

	void Deposit(const int deposit)
	{
		money += deposit;
	}
	int WithDraw(const int draw)
	{
		money -= draw;
		return money;
	}

	const char* GetOwner() const
	{
		return name;
	}
	int GetInquiry() const
	{
		return money;
	}

private:
	char name[256];
	int num;
	int money;
};

int main()
{
	Account a("kitae", 1, 5000);

	a.Deposit(50000);
	cout << a.GetOwner() << "의 잔액은 " << a.GetInquiry() << endl;
	int money = a.WithDraw(20000);
	cout << a.GetOwner() << "의 잔액은 " << a.GetInquiry() << endl;
	
}