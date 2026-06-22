#include <iostream>

#include "queue.h"
using namespace std;


int main()
{
	Homework::queue<int> qu;
	int input{};
	cin >> input;

	for (int i = 0; i < input; ++i)
	{
		qu.push(1);
		qu.push(2);
		qu.push(3);
		cout << qu.front();
		qu.pop();
		cout << qu.front();
		qu.pop();
		cout << qu.front();
		qu.pop();
	}
}