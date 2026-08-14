#include <iostream>

using namespace std;

int vect[10]{ 1,2,3,4,5,6,7,8,9 };
int target = 7;

void runrecursive(int start, int end)
{
	int mid = (start + end) / 2;

	if (vect[mid] == target)
	{
		cout << "found" << endl;
		return;
	}
	else if (vect[mid]<target)
		runrecursive(mid+1,end);
	else
		runrecursive(start, mid-1);
}


int main()
{
	runrecursive(0,7);
}