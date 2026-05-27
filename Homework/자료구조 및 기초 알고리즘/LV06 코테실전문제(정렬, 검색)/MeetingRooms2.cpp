#include <iostream>
using namespace std;

struct intervals
{
	int s;
	int e;
};

int main()
{
	int n{};
	intervals interval[5000]{};

	for (int i = 0; i < n; ++i)
	{
		cin >> interval[i].s >> interval[i].e;
	}

	if (n == 1)
	{
		cout << 1;
		return 0;
	}

	for (int i = 0; i < n; ++i)
	{
		
	}
}