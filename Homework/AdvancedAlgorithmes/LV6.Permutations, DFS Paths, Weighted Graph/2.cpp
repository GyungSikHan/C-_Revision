#include <iostream>
#include <algorithm>
using namespace std;

int nextPermutation(int* data, int n)
{
	int i = n - 1;
	
	while (i > 0 && data[i - 1] >= data[i])
		i -= 1;
	if (i <= 0)
		return 0;

	int j = n - 1;
	
	while (data[j] <= data[i - 1])
		j -= 1;

	swap(data[i-1], data[j]);

	j = n - 1;

	while (i<j)
	{
		swap(data[i], data[j]);
		i++;
		j--;
	}

	return 1;
}

int main()
{
	int data[4]{ 1,2,3,4 };
	int n = 4;
	int result{};

	//while (true)
	//{
	//	for (int i = 0; i < 4; ++i)
	//	{
	//		cout << data[i];
	//	}
	//	cout << endl;

	//	if (!next_permutation(data, data+4))
	//		break;
	//	/*result = nextPermutation(data,n);
	//	if (result == 0)
	//		break;*/
	//}

	do
	{
		for (int i = 0; i < 4; ++i)
		{
			cout << data[i];
		}
		cout << endl;
	}
	while (next_permutation(data, data+4));
}