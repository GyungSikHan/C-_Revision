#include<iostream>
using namespace  std;

int main()
{
	int input{};
	cin >> input;

	int cnt{};
	while (cnt != 3)
	{
		int cnt2{};
		while (cnt2 != 5)
		{
			cout << input;
			cnt2++;
		}
		cout << endl; 
		cnt++;
	}
}