#include <iostream>

using namespace std;

void Input(int* input)
{
	cin >> *input;
}

void CountDown(int input)
{
	for (int i = input; i > 0; i--)
		cout << i<<" ";
}

int main()
{
	int input{};
	Input(&input);
	CountDown(input);
}