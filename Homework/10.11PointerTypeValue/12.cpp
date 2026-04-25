#include<iostream>

using namespace std;

char aToZ(char input)
{
	int temp = input - 'A';

	if (temp <= 12)
		return 'A';
	return 'Z';
}

int main()
{
	char input = 'A';
	cin >> input;
	cout << aToZ(input) << endl;
}