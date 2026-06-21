#include <iostream>
#include "LinkedList.h"
using namespace std;


int main()
{
	LinkedList<int> list;
	int size{};
	cin >> size;
	for (int i = 0; i < size; ++i)
	{
		int value{};
		cin >> value;
		list.push_back(value);
	}

	int erase{};
	cin >> erase;

	list.remove(erase);

	for (LinkedList<int>::iterator iter = list.begin(); iter != list.end(); ++iter)
	{
		cout << (*iter) << " ";
	}
}