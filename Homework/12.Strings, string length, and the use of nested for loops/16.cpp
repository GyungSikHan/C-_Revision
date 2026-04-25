#include <iostream>
using namespace std;

int main()
{
	int vect[100]{};
	char arr[CHAR_MAX]{};
	
	cin >> arr;
	
	int idx{};
	int cnt{};
	while (arr[idx] != '\0')
	{
		idx++;
	}
	for (int i = 0; i< idx; i++)
	{
		if (arr[i] == arr[idx - 1])
			cnt++;
	}
	cout << idx << endl;
	cout << cnt << endl;
}