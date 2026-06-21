#include <iostream>
#include "LinkedList.h"
using namespace std;

int main()
{
	int len{};
	cin >> len;

	LinkedList<int> list;
	for (int i = 0; i < len; ++i)
	{
		int a{};
		cin >> a;
		list.push_back(a);
	}

	list.reverse();
	for (auto iter = list.begin(); iter != list.end(); ++iter)
	{
		cout << (*iter) << " ";
	}
}