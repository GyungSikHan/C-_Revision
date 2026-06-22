#include <iostream>

#include "queue.h"
using namespace std;

int main()
{
	int input{};
	while (cin>>input)
	{
		if (input >= 11 && input <= 36)
			break;
		cout << "다시 입력, 11~36 사이" << endl;
	}

	Homework::queue<char> qu;

	int len = 'A'+(input - 11);
	for (int i = len; i <= len+3; ++i)
		qu.push((char)i);
	
	for (auto iter = qu.begin(); iter != qu.end(); ++iter)
	{
		cout << (*iter) << " ";
	}

}