#include <iostream>

using namespace std;

int main()
{
	int input{};
	cin >> input;

	for (int i = 0; i< 4; i++)
	{
		for (int j = 0; j<4; j++)
		{
			cout << input;
		}
		cout << endl;
		input--;
	}
}