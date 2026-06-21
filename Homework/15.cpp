#include <iostream>
using namespace std;

class Array
{
public:
	Array(int len)
	: count(len)
	{
		arr = new int[count] {};

		for (int i = 0; i < count; ++i)
		{
			arr[i] = rand() % 10;
		}
	}
	void PrintArray()
	{
		for (int i = 0; i < count; ++i)
			cout << arr[i]<<" ";
		cout << endl;
	}
	
	~Array()
	{
		delete[] arr;
		arr = nullptr;
		count = 0;
	}
private:
	int count;
	int* arr;
};

int main()
{
	srand(time(NULL));
	Array arr1(3);
	Array arr2(5);

	arr1.PrintArray();
	arr2.PrintArray();
}