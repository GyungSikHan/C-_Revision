#include <iostream>

using namespace std;

const int length = 5;
const int MAX_DATA = 987654321;

char oper[4]{ '*','-','*','+' };
int arr[length]{};
int visited[length]{};
int MIN = MAX_DATA;
int MAX = -MAX_DATA;

int Operate(int a, int b, char c)
{
	if (c == '+')
		return a + b;
	if (c == '-')
		return a - b;
	if (c == '*')
		return a * b;
	return a / b;
}

void Solution(int index, int* data)
{
	if (index == 5)
	{
		int temp = (data[0] * data[1]) - (data[2] * data[3]) + data[4];
		
		MIN = min(temp, MIN);
		MAX = max(temp, MAX);
		return;
	}

	for (int i = 0; i < length; ++i)
	{
		if (visited[i] == 1 || data[index] != -1)
			continue;
		visited[i] = 1;
		data[index] = arr[i];
		Solution(index + 1, data);
		data[index] = -1;
		visited[i] = 0;
	}
}

int main()
{
	for (int i = 0; i < length; ++i)
		cin >> arr[i];
	int data[length]{};
	memset(data, -1, sizeof(data));

	Solution(0, data);

	cout << MAX << endl;
	cout << MIN << endl;
}