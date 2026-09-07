#include <iostream>
#include <vector>

using namespace std;

int n{};
int ret{};

void BinarySearch(int start, int end)
{
	if (start > end)
	{
		return;
	}

	ret++;
	int mid = (start + end) / 2;
	if (mid*mid > n)
	{
		BinarySearch(start, mid-1);
	}
	else
	{
		BinarySearch(mid+1,end);
	}
}

int main()
{
	cin >> n;
	BinarySearch(0, n);

	cout << ret;
}