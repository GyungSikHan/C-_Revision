#include <iostream>
#include "LinkedList.h"
using namespace std;

int main()
{
	int n{};
	cin >> n;
	ya::list<int> list;
	for (int i = 0; i < n; ++i)
	{
		int a{};
		cin >> a;
		list.push_back(a);
	}

	list.OddEvenLinkedList();

	for (auto iter = list.begin(); iter != list.end(); ++iter)
	{
		cout << (*iter) << " ";
	}
}