#include <iostream>
using namespace std;

int yesOrNot()
{
	int input{};
	
	cin >> input;

	int mod = input % 3;

	if (mod == 0)
		return 7;
	else if (mod == 1)
		return 35;
	return 50;
}

int main()
{
	cout << yesOrNot() << endl;
}