#include <iostream>
using namespace std;

int main()
{
	int vec[10]{ 1,2,3,4,5,6,7,8,9,10 };

	int max = vec[0];
	int min = vec[0];

	int maxIdx{};
	int minIdx{};

	for (int i = 0; i < 10; ++i)
	{
		if (max < vec[i])
		{
			maxIdx = i;
			max = vec[i];
		}
		if (vec[i] < min)
		{
			minIdx = i;
			min = vec[i];
		}
	}
	cout << maxIdx << " " << max << endl;
	cout << minIdx << " " << min << endl;
}