#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int arr[7]{ 3,5,5,6,9,1,2 };
	int s{}, e{};
	cin >> s >> e;

	while (s < e)
	{
		std::swap(arr[s], arr[e]);
		s++;
		e--;
	}

	for (int i = 0; i < 7; ++i)
		cout << arr[i] << " ";
}