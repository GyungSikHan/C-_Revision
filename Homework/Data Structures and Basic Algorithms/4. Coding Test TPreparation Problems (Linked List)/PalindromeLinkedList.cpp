#include <iostream>
#include "LinkedList.h"
using namespace std;

int main()
{
	int len{};
	cin >> len;
	LinkedList<int>list;
	for (int i = 0; i < len; ++i)
	{
		int a{};
		cin >> a;
		list.push_back(a);
	}

	LinkedList<int> list2 = list;
	list2.reverse();

	cout << (list == list2 ? "true" : "false") << endl;
}