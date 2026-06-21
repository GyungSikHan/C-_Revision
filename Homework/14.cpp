#include <iostream>
#include <algorithm>
using namespace std;

void Permitation(int n, int idx, char* arr)
{
	if (n == idx)
	{
		cout << arr << endl;
		return;
	}

	for (int i = 1; i <= 6; ++i)
	{
		arr[idx] = (char)i + '0';
		Permitation(n, idx + 1, arr);
	}
}

int main()
{
	int n{};
	cin >> n;
	char arr[256]{};
	Permitation(n, 0, arr);
}