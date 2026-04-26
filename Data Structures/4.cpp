#include <iostream>
using namespace std;

int main()
{
	int mask[4]{ 1,1,0,1 };
	int arr[4]{ 3,7,45,8 };
	int ret[4]{ 0,0,0,0 };

	for (size_t i = 0; i < 4; ++i)
	{
		if (mask[i] == 1)
			ret[i] = arr[i];
	}

	cout << "원본 배열: ";
	for (int i = 0; i < 4; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	cout << "마스크 배열: ";
	for (int i = 0; i < 4; ++i)
	{
		cout << mask[i] << " ";
	}
	cout << endl;

	cout << "결과 배열: ";
	for (int i = 0; i < 4; ++i)
	{
		cout << ret[i] << " ";
	}
	cout << endl;
}