#include <iostream>
using namespace std;

int main()
{
	char arr[2][9]{};	
	for (int i = 0; i < 2; i++)
	{
		cin>>arr[i];
	}

	int idx{};

	for (int i = 0; i < 9; i++)
	{
		if(arr[0][i] != arr[1][i])
			idx++;
	}
	
	cout<<idx;
	
}