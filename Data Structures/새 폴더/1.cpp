#include <iostream>
using namespace std;

int main()
{
	int num[301]{};
	int ret[301]{};
	int n{};
	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> num[i];

	for (int i = 0; i < n; ++i)
	{
		ret[num[i]]++;
	}

	for (int i = 0; i < n; ++i)
	{
		while (ret[i] != 0)
		{
			cout << i << " ";
			ret[i]--;
		}
	}
	
}