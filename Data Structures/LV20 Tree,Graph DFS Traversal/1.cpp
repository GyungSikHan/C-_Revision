#include<iostream>
using namespace std;

int main()
{
	char value[10]{ "DEFQZVM" };
	int map[7][7]
	{
		0,1,1,1,0,0,0,
		0,0,0,0,1,0,0,
		0,0,0,0,0,0,0,
		0,0,0,0,0,1,1,
		0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,
		0,0,0,0,0,0,0
	};

	int n{};
	cin >> n;

	for (int i = 0; i < 7; ++i)
		if (map[n][i] > 0)
			cout << value[i] << endl;
	
}