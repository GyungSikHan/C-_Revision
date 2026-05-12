#include <iostream>
using namespace std;

void InputData(int* input, int* size)
{
	for (int i = 0; i < 10; ++i)
	{
		int data{};
		cin >> data;

		if (data == 0)
			break;
		input[i] = data;
		size++;
	}
}

void SumArray(int* dest, const int* src1, const int src1Size, const int* src2, const int src2Size)
{
	for (int i = 0; i < src1Size; ++i)
	{
		dest[i] = src1[i];
	}

	for (int i = 0; i < src2Size; ++i)
	{
		dest[src1Size + i] = src2[i];
	}
}

int main()
{
	int nums1[10]{};
	int nums2[10]{};
	int m{}, n{};

	InputData(nums1, &m);
	InputData(nums2, &n);

	int sort[12]{};
	SumArray(sort, nums1, m, nums2, n);
	int a{};
}