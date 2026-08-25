#include <iostream>

using namespace std;

const int length = 10;
int arr[length]{ 4,4,5,7,8,10,20,22,23,25 };

bool BinarySearch(const int target, int start, int end)
{
	int mid = (start + end) / 2;
	int temp = arr[mid];
	if (temp == target)
		return true;
	else if (temp < target)
		return BinarySearch(target, mid+1, end);
	else
		return BinarySearch(target, start, mid-1);

	return false;
}
int main()
{
	int target{};
	cin >> target;

	cout << (BinarySearch(target, 0, length - 1) == true ? "O" : "X") << endl;
}