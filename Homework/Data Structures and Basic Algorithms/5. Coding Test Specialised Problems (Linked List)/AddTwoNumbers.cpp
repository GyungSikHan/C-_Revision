#include <iostream>
#include "LinkedList.h"
using namespace std;

void Add(int len, int len2, const ya::list<int> list, ya::list<int> list2, ya::list<int>& ret)
{
	int a{};
	for (int i = 0; i < len; ++i)
	{
		int b = list.find(i) + list2.find(i) + a;
		int c = b % 10;

		a = b / 10;
		ret.push_back(c);
	}

	for (int i = len; i < len2; ++i)
	{
		int b = list.find(i) + a;
		int c = b % 10;
		a = b / 10;

		ret.push_back(c);
	}
	if (a>0)
		ret.push_back(a);
}

void Add(const int len, const ya::list<int> list, const ya::list<int>list2, ya::list<int>& ret)
{
	int a{};
	for (int i = 0; i < len; ++i)
	{
		int b = list.find(i) + list2.find(i) + a;
		int c = b % 10;

		a = b / 10;
		ret.push_back(c);
	}
	if (a > 0)
		ret.push_back(a);
}

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

	int n2{};
	cin >> n2;
	ya::list<int> list2;
	for (int i = 0; i < n2; ++i)
	{
		int a{};
		cin >> a;
		list2.push_back(a);
	}

	ya::list<int> list3;
	if (n < n2)
		Add(n,n2,list,list2, list3);
	else if(n > n2)
		Add(n2, n, list2, list, list3);
	else
		Add(n,list,list2,list3);

	for (auto iter = list3.begin(); iter != list.end(); ++iter)
	{
		cout << (*iter) << " ";
	}
}