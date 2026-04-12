#include<iostream>

int main()
{
	int arr[3][3]{};
	int num = 1;

	for (int i = 2; i >= 0; i--)
	{
		for (int j = i; j < 3; j++)
		{
			arr[i][j] = num;
			num++;
		}
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cout << arr[i][j];
		}
		std::cout << std::endl;
	}
}