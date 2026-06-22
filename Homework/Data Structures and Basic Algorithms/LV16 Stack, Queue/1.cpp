#include <iostream>
#include "queue.h"
using namespace std;


int main()
{
	Homework::queue<int> qu;

	int input{};
	cin >> input;

	for (int i = 1; i <= 4; ++i)
		qu.push(i*input);

	for (auto iter = qu.begin(); iter != qu.end(); ++iter)
	{
		cout << (*iter) << " ";
	}
}