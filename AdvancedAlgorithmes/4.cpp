#include <iostream>
#include <queue>

using namespace std;

int vect[10]{ 1,2,3,4,5,6,7,8,9 };
int target = 7;

void runrecursive(int start, int end)
{
	int mid = (start + end) / 2;

	if (vect[mid] == target)
	{
		cout << "find" << endl;
		return;
	}
	else if (vect[mid] < target)
		runrecursive(vect[mid]+1, end);
	else
		runrecursive(start, vect[mid]-1);
}

void run()
{
	int start{};
	int end = 9;

	bool flag{};
	while (start<=end)
	{
		int mid = (start + end) / 2;
		
		if (vect[mid] == target)
		{
			flag = true;
			cout << "find" << endl;
			break;
		}
		else if (vect[mid] < target)
			start = mid + 1;
		else
			end = mid - 1;
	}

	if (!flag)
		cout << "Not Found" << endl;
}

int main()
{
	//runrecursive(0, 9);
	run();
}