#include <iostream>
using namespace std;

void FindABC(char* arr1, char* arr2, int* A,int* B, int* C)
{
	int idx1{};
	int idx2{};
	while (idx1 != -1 || idx2 != -1)
	{
		if (idx1 != -1)
		{
			if (arr1[idx1] == '\0')
			{
				idx1 = -1;
				continue;
			}
			else if (arr1[idx1] == 'A')
				(*A)++;
			else if (arr1[idx1] == 'B')
				(*B)++;
			else if (arr1[idx1] == 'C')
				(*C)++;
			idx1++;
		}
		if (idx2 != -1)
		{
			if (arr2[idx2] == '\0')
			{
				idx2 = -1;
				continue;
			}
			else if (arr2[idx2] == 'A')
				(*A)++;
			else if (arr2[idx2] == 'B')
				(*B)++;
			else if (arr2[idx2] == 'C')
				(*C)++;

			idx2++;
		}
		
	}
}

int main()
{
	char arr1[CHAR_MAX]{};
	char arr2[CHAR_MAX]{};
	int A{}, B{}, C{};
	cin >> arr1 >> arr2;

	FindABC(arr1, arr2, &A, &B, &C);

	cout << "A:" << A << endl;
	cout << "B:" << B << endl;
	cout << "C:" << C << endl;
}