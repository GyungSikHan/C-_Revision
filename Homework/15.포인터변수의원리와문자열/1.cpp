#include <iostream>
using namespace std;

int main()
{
	int vect[7]{ 3,5,1,1,2,3,2 };
	int arr[4]{};
	for (int i = 0; i < 4; ++i)
	{
		cin >> arr[i];
	}

	int ret[9]{};
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 7; ++j)
		{
			if (arr[i] == vect[j])
				ret[arr[i]]++;
		}
	}

	for (int i = 0; i < 4; ++i)
	{
		cout << arr[i] << "=" << ret[arr[i]] << "개" << endl;
	}
}