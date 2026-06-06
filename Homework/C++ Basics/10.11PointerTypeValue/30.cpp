#include <iostream>

using namespace std;

int arr[7][5]
{
	1,0,0,0,0,
	1,0,1,0,0,
	1,1,0,1,0,
	1,0,1,0,0,
	0,1,0,0,1,
	0,0,0,1,0,
	1,1,0,0,0
};
void OUTPUT(int data)
{
	cout << data;
}

void PROCESS(int input)
{
	int cnt{};
	for (int i = 0; i< 7; i++)
	{
		if (arr[i][input] == 1)
			cnt++;
	}

	OUTPUT(cnt);
}

void INPUT()
{
	int input{};
	cin >> input;

	PROCESS(input);
}

int main()
{
	INPUT();
}