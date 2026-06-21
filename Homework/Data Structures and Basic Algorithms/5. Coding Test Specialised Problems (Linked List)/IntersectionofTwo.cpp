#include <iostream>
#include "LinkedList.h"
using namespace std;

int main()
{
	ya::list<int> headA;
	ya::list<int> headB;
	int skipA{}, skipB{};
	int intersectVal{};
	cin >> intersectVal;

	int n{}, n2{};
	cin >> n >> n2;
	for (int i = 0; i < n; ++i)
	{
		int a{};
		cin >> a;
		if (a == intersectVal)
			skipA = i;
		headA.push_back(a);
	}
	for (int i = 0; i < n2; ++i)
	{
		int a{};
		cin >> a;
		if (a == intersectVal)
		{
			skipB = i;
			break;
		}
		headB.push_back(a);
	}

	headB.IntersectVal(headA.SerchNode(intersectVal));

	cout << "headA skipA : " << skipA << ", Node.data = ";
	for (auto iter = headA.begin(); iter != headA.end(); ++iter)
		cout << (*iter) << " ";
	cout << endl;
	cout << "headB skipB : " << skipB << ", Node.data = ";
	for (auto iter = headB.begin(); iter != headB.end(); ++iter)
		cout << (*iter) << " ";
}