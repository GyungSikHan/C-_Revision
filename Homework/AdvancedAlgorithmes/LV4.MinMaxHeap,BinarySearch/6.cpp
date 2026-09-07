#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

char str[11]{};

int main()
{
	cin >> str;

	int start{}, end = 10;
	int answer{};
	while (start <= end)
	{
		int mid = (start + end) / 2;
		if (str[mid] == '#')
		{
			start = mid + 1;
		}
		else
		{
			answer = mid;
			end = mid - 1;
		}
	}

	cout << answer * 10 << "%";
}