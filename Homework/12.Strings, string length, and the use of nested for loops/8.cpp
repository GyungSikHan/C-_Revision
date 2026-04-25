#include <iostream>
using namespace std;

int main()
{
	char arr[10] = "DATAPOWER";
	int a{}, b{};
	char arr2[9]{};

	cin >> a >> b;

	int idx{};
	for (int i = a; i<=b; i++)
	{
		arr2[idx++] = arr[i];
	}

	cout << arr2 << endl;
}