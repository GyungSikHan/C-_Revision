#include<iostream>

using namespace std;

int main()
{
	int vect[7] = { 5, 6, 7, 1, 2, 3, 8 };
	int min = INT_MAX;
	int max = INT_MIN;

	for (int i = 0; i < 7; i++)
	{
		if (vect[i] < min)
			min = vect[i];

		if (vect[i] > max)
			max = vect[i];
	}

	cout << "min: " << min << endl;
	cout << "max: " << max << endl;
}