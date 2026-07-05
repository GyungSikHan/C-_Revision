#include <iostream>
#include <vector>
using namespace std;

const int lenght = 4;

int arr[lenght]{};
int arr2[lenght]{};
vector<int>ret;

void InputData(int* array)
{
	for (int i = 0; i < lenght; ++i)
		cin >> array[i];
}

void Print()
{
	for (int iter : ret)
		cout << iter << " ";
}

void Rest(int* data, int idx)
{
	for (int i = idx; i < lenght; ++i)
		ret.push_back(data[i]);
}

void Solution()
{
	int idx{}, idx2{};
	while (idx != lenght && idx2!= lenght)
	{
		if (arr[idx] < arr2[idx2])
			ret.push_back(arr[idx++]);
		else if (arr[idx] > arr2[idx2])
			ret.push_back(arr2[idx2++]);
		else
		{
			ret.push_back(arr[idx]);
			ret.push_back(arr[idx]);
			idx++; idx2++;
		}
	}
	Rest(arr, idx);
	Rest(arr2, idx2);


	Print();
}

int main()
{
	InputData(arr);
	InputData(arr2);
	Solution();
}