#include <iostream>
using namespace std;

int main()
{
	int n{};
	cin >> n;
	int arr[100001]{};

	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	int ret[100][3]{};

	for (int i = 1; i < n; ++i)
	{
		int key = arr[i];
		int j = i - 1;
		while (j >= 0)
		{
			if (key < arr[j])
			{
				arr[j+1] = arr[j];
				j--;
			}
			else
				break;
		}
		arr[j + 1] = key;
	}

	int idx{};
	for (int i = 0; i < n-2; ++i)
	{
		if (i > 0 && arr[i] == arr[i - 1])
			continue;

		int j = i + 1;
		int k = n - 1;

		while (j < k)
		{
			int sum = arr[i] + arr[j] + arr[k];
			if (sum == 0)
			{
				ret[idx][0] = i;
				ret[idx][1] = j;
				ret[idx][2] = k;
				idx++;
				j++;
				k--;
			}
			else if (sum < 0)
				j++;
			else
				k--;
		}
	}

	for (int i = 0; i < idx; ++i)
	{
		cout << arr[ret[i][0]] << " " << arr[ret[i][1]] << " " << arr[ret[i][2]] << endl;
	}
}