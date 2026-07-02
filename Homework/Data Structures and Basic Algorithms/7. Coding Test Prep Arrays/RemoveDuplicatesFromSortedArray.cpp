#include <iostream>
using namespace std;
const int length = 100;

struct Data
{
	int arr[length]{};
	int size{};
};

void RemoveDuplicates(Data& data, const int* nums, const int size)
{
	int ret[length]{};
	int retSize = 1;
	ret[0] = nums[0];

	for (int i = 1; i < size; ++i)
	{
		bool bFlag{};
		for (int j = 0; j < retSize; ++j)
		{
			if (ret[j] == nums[i])
			{
				bFlag = true;
				break;
			}
		}
		if (!bFlag)
		{
			ret[retSize] = nums[i];
			retSize++;
		}
	}

	data.size = retSize;
	memcpy(data.arr, ret, length);
}

int main()
{
	int nums[100]{};
	int size{};

	cin >> size;
	for (int i = 0; i < size; ++i)
	{
		cin >> nums[i];
	}

	Data data{};
	RemoveDuplicates(data, nums, size);
	cout <<"k = "<< data.size << " Data = ";
	for (int i = 0; i < data.size; ++i)
		cout << data.arr[i]<<" ";
}