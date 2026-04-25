#include <iostream>

using namespace std;

int main()
{
	struct BBQ
	{
		int x;
		int data[3];
	};

	BBQ g;
	cin >> g.x;
	for (int i = 0 ; i < 3; i++)
	{
		cin >> g.data[i];
	}

	int sum{};
	for (int i = 0 ; i < 3; i++)
	{
		sum += g.data[i];
	}

	cout << sum << " " << g.x << endl;
}