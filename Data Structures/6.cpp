#include <iostream>
using namespace std;

int arr[5]{ 1,5,1,5,3 };
int input[3]{ 1,2,3 };

int isExist(int data)
{
	for (size_t i = 0; i < 5; ++i)
	{
		if (arr[i] == data)
			return 1;
	}

	return 0;
}

int main()
{
	for (size_t i = 0; i < 3; ++i)
	{
		int flag = isExist(input[i]);

		if (flag)
			cout << "존재 O" << endl;
		else
			cout << "존재 X" << endl;
	}
}