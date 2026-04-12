#include <iostream>
using namespace std;

int GOP()
{
	int num1{}, num2{};
	cin >> num1 >> num2;
	return num1 * num2;
}

int SUM()
{
	int num1{}, num2{};
	cin >> num1 >> num2;
	return num1 + num2;
}

int main()
{
	int gop = GOP();
	int sum = SUM();

	if (gop > sum)
		cout << "GOP" << endl;
	else if (gop < sum)
		cout << "SUM" << endl;
	else
		cout <<"GOP == SUM"<< endl;
}