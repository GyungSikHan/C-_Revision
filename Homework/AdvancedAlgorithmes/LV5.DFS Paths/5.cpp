#include <iostream>

using namespace std;

const int length = 6;
int input;
int arr[length];
int hol{}, jjag{}, total{};

void Solution(int Count, int data)
{
	if (Count == 4)
	{
		total++;
		if (data % 2 == 0)
			jjag++;
		else
			hol++;
		return;
	}

	for (int i = 0; i < length; ++i)
	{
		if (arr[i] == 0)
			continue;

		Solution(Count + 1, data * 10 + arr[i]);
	}
}

int main()
{
	cin >> input;
	int i{};
	while (input != 0)
	{
		arr[i++] = input % 10;
		input /= 10;
	}

	Solution(0,0);
	cout << total << " " << jjag << " " << hol;
}