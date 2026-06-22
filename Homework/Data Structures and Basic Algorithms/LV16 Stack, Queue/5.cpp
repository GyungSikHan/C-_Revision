#include <iostream>

#include "queue.h"
using namespace std;

int main()
{
	int input1{}, input2{};
	cin >> input1 >> input2;

	Homework::queue<char> qu;
	for (int i = 0; i < input1; ++i)
	{
		char c{};
		cin >> c;

		qu.push(c);
	}

	for (int i = 0; i < input2; ++i)
		qu.pop();

	for (auto iter = qu.begin(); iter != qu.end(); ++iter)
		cout << (*iter) << " ";
}