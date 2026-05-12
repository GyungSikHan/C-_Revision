#include <iostream>
using namespace std;

struct MC
{
	char Burger1[256];
	char Burger2[256];
};

int CountStr(const char* str)
{
	int idx{};
	while (str[idx] != '\0')
		idx++;

	return idx;
}

int main()
{
	MC bob;
	MC tom;

	cin >> bob.Burger1;
	cin >> bob.Burger2;
	cin >> tom.Burger1;
	cin >> tom.Burger2;

	cout<<"bob.burger1="<<CountStr(bob.Burger1)<<endl;
	cout<<"bob.burger2="<<CountStr(bob.Burger2)<<endl;
	cout<<"tom.burger1="<<CountStr(tom.Burger1)<<endl;
	cout<<"tom.burger2="<<CountStr(tom.Burger2)<<endl;
}