#include <iostream>
using namespace std;

const int index = 4;

int main()
{
	char str[256]{};
	cin >> str;
	int data[index]{};
	for (int i = 0; i < index; ++i)
		cin>>data[i];

	int* p[4]{ &data[0],&data[1],&data[2],&data[3] };

	for (int i = 0; i < index; ++i)
		cout << str[*p[i]];
}