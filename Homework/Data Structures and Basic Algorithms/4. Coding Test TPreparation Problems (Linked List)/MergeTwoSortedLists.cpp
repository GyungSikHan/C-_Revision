#include <algorithm>
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

	cin >> len;
	LinkedList<int> list2;
	for (int i = 0; i < len; ++i)
	{
		int a{};
		cin >> a;
		list2.push_back(a);
	}

	LinkedList<int> list3 = list + list2;
	list3.sort();
	for (auto iter = list3.begin(); iter != list3.end(); ++iter)
	{
		cout << (*iter) << " ";
	}
}