#include <iostream>
using namespace  std;

int main()
{
	int arr[6]{ 5,1,3,7,2,9 };

	for (int i = 0; i<5; i++)
	{
		for (int j = i+1; j<6; j++)
		{
			if (arr[j]<arr[i])
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}		
		}
	}

}