#include <iostream>
#include <vector>
using namespace std;

int n{};
vector<int> v;

int main()
{
	cin >> n;
	v.assign(n, 0);

	for (int i = 0; i < n; ++i)
		cin >> v[i];

	int ret{};
	int startIndex{}, endIndex{};
	for (int i = 0; i < n; ++i)
	{
		int temp{};
		int tempindx1 = i;
		int tempindx2{};
		int sum = v[i];
		for (int j = i+1; j < n; ++j)
		{
			if (sum + v[j] < 0)
				break;

			sum += v[j];
			if (temp < sum)
			{
				temp = sum;
				tempindx2 = j;
			}
		}

		if (ret < temp)
		{
			ret = temp;
			startIndex = tempindx1;
			endIndex = tempindx2;
		}
	}

	cout << startIndex << " " <<endIndex;
}