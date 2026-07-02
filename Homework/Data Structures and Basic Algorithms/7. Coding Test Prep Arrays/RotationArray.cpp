#include <iostream>
using namespace std;

const int length = 100000;

void Rotation(int* nums, const int size, const int k, int cnt)
{
	if (cnt == k)
		return;
	

	int temp = nums[size - 1];

	for (int i = size-1; i >= 1; --i)
		nums[i] = nums[i - 1];
	nums[0] = temp;
	Rotation(nums, size, k, cnt + 1);
}

int main()
{
	int nums[length]{}; 
	int len{};
	cin >> len;

	for (int i = 0; i < len; ++i)
		cin >> nums[i];

	int k{};
	cin >> k;
	Rotation(nums,len,k,0);

	for (int i = 0; i < len; ++i)
		cout << nums[i] << " ";
}