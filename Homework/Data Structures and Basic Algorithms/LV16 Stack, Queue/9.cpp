#include <iostream>
using namespace std;

int map[4][4]
{
	3,5,1,4,
	2,2,1,1,
	0,1,2,3,
	3,1,3,1
};

void printRow(const int* arr)
{
	for (int i = 0; i < 4; ++i)
		cout << arr[i];
}
void printCol(const int index)
{
	for (int i = 0; i < 4; ++i)
	{
		cout<<map[i][index];
	}
}
int main()
{
	char input{};
	cin >> input;

	if ('0' <= input && input <= '9')
		printRow(map[input - '0']);
	else
		printCol(input - 'A');
}