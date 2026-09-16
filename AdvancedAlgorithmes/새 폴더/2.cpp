#include <iostream>

using namespace std;

int vect[5]{6,1,4,8,5};
int results[5]{};

void run(int start, int end)
{
	int mid = (start + end) / 2;

	//
	if (start >= end)
		return;

	run(start, mid);
	run(mid+1,end);

	int a = start;
	int b = mid+1;
	int t = 0;

	while (true)
	{
		if (a > mid && b > end)
			break;

		if (a > mid)
			results[t++] = vect[b++];
		else if (b > end)
			results[t++] = vect[a++];
		else if (vect[a] <= vect[b])
			results[t++] = vect[a++];
		else
			results[t++] = vect[b++];
	}

	for (int i = 0; i < t; ++i)
	{
		vect[start + i] = results[i];
	}
}

int main()
{
	run(0, 4);

	for (int i = 0; i < 5; ++i)
	{
		cout << results[i] << " ";
	}
}