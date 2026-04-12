#include<iostream>
using namespace std;

int main()
{
	int vec[7] = { 5,6,7,1,2,3,8 };
	int max = INT_MIN;
	int min = INT_MAX;

	for (int i = 0; i < 7; i++)
	{
		if (max < vec[i])
			max = vec[i];
	}

	for (int i = 0; i < 7; i++)
	{
		if (min > vec[i])
			min = vec[i];
	}
	
	cout << "최대값: " << max << endl;
	cout << "최소값: " << min << endl;

	return 0;
}