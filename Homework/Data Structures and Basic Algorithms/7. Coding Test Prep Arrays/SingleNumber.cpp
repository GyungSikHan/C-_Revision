#include <iostream>
using namespace std;

const int lenght = 30000;
int main()
{
	int size{};
	int nums[lenght]{};

	cin >> size;
	for (int i = 0; i < size; ++i)
		cin >> nums[i];

	int cnt[lenght * 2 + 1]{};

	for (int i = 0; i < size; ++i)
		cnt[nums[i]]++;
	for (int i = 0; i < lenght*2+1; ++i)
	{
		if (cnt[i] == 1)
		{
			cout << i;
			break;
		}
	}
}