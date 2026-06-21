#include <iostream>
#include "LinkedList.h"
using namespace std;

int main()
{
	int n{};
	cin >> n;
	LinkedList<int> list;
	for (int i = 0; i < n; ++i)
	{
		int a{};
		cin >> a;
		list.push_back(a);
	}

	int cycleIndex{};
	cin >> cycleIndex;
	cout << (list.Cycle(cycleIndex) ? "true" : "false") << endl;
}