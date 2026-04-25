#include <algorithm>
#include <iostream>
using namespace std;

void Sort(char (*arr)[6], int idx)
{
	for (int i = 0; i < 5; ++i)
	{
		for (int j = i+1; j < 6; ++j)
		{
			if (arr[idx][j] == '\0')
				break;
			if (arr[idx][j-1] > arr[idx][j])
			{
				int temp = arr[idx][j-1];
				arr[idx][j - 1] = arr[idx][j];
				arr[idx][j] = temp;
			}
		}
	}
}

int main()
{
	char arr[2][6]{ "DATAW", "BBQK" };
	int input{};
	int idx{};
	cin >> input;
	
	if (input % 2 == 1)
		idx = 0;
	else
		idx = 1;

	Sort(arr, idx);
	for (int i = 0; i < 2; ++i)
	{
		cout << arr[i] << endl;
	}
}