#include <iostream>
using namespace std;

void KFC(int* big, int* small)
{
	char arr[11]{};
	cin >> arr;

	int idx{};
	while (arr[idx] != '\0')
	{
		if ('a' <= arr[idx] && arr[idx] <= 'z')
			(*small)++;
		else
			(*big)++;

		idx++;
	}
}

int main()
{
	int big{}, small{};

	KFC(&big,&small);
	cout << "대문자" << big << "개" << endl;
	cout << "소문자" << small << "개" << endl;
}