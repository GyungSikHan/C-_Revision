//#include <iostream>
//using namespace std;
//
//int main()
//{
//	int nums[100001]{};
//	int n{};
//	int max{};
//
//	cin >> n;
//	for (int i = 0; i < n; ++i)
//	{
//		cin >> nums[i];
//		if (nums[i] > max)
//			max = nums[i];
//	}
//
//	int ret[100001]{};
//	for (int i = 0; i < n; ++i)
//	{
//		ret[nums[i]]++;
//	}
//	int k{};
//	cin >> k;
//	for (int i = max; i >= 0; --i)
//	{
//		if (ret[i] != 0)
//		{
//			k--;
//			if (k == 0)
//			{
//				cout << i;
//				break;
//			}
//		}
//	}
//}