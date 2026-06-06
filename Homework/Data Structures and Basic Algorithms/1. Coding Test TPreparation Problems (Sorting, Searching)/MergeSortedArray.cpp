#include <iostream>
using namespace std;

void InputData(int* input, const int size)
{
	if(size == 0 )
		return;

	for (int i = 0; i < size; ++i)
	{
		cin >> input[i];
	}
}

void SumArray(int* src1, const int src1Size, const int* src2, const int src2Size)
{
	int idx{};
	for (size_t i = src1Size; i < src1Size+src2Size; i++)
	{
		src1[i] = src2[idx++];
	}
	
}

void Sort(int* sort, const int* size)
{
	for (size_t i = 0; i < *size; i++)
	{
		for (size_t j = i+1; j < *size; j++)
		{
			if(sort[i] > sort[j])
			{
				int temp = sort[i];
				sort[i] = sort[j];
				sort[j] = temp;
			}
		}
	}
}

void Print(const int* data, const int* size)
{
	for (size_t i = 0; i < *size; i++)
	{
		cout<<data[i]<<" ";
	}
	
}

int main()
{
	int nums1[100]{};
	int nums2[100]{};
	int m{}, n{}, idxSum;
	cin>>m>>n;

	InputData(nums1, m);
	InputData(nums2, n);

	SumArray(nums1, m, nums2, n);
	idxSum = m+n;

	Sort(nums1, &idxSum);
	Print(nums1, &idxSum);
}