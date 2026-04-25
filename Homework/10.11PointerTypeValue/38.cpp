#include <iostream>
using namespace std;

void CompareGo(const int* arr, const int* arr2, int length)
{
	bool bFlag{};
	for (int i = 0; i < length; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			if (arr[i] != arr2[j])
			{
				bFlag = true;
				break;
			}
		}
	}

	if (bFlag)
		cout << "두배열은같지않음" << endl;
	else 
		cout << "두배열은같음" << endl;
}

int main()
{
	int arr[5]{ 3,5,1,2,7 };
	int arr2[5]{};
	
	for (int i = 0; i< 5; i++)
	{
		cin >> arr2[i];
	}

	CompareGo(arr, arr2, 5);
}