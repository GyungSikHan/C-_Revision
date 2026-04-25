#include <iostream>
using namespace std;

int main()
{
	/*char test[10] = "HELLO";

	char ch = 'A';
	char* p = &ch;

	p = test;

	cout << "*p: " << *p << endl;
	cout << "*(p+1): " << *(p+1) << endl;
	cout << "*(p+2): " << *(p+2) << endl;

	cout << "p[0]: " << p[0] << endl;
	cout << "p[1]: " << p[1] << endl;
	cout << "p[2]: " << p[2] << endl;

	int test2[10] = {1,2,34,5,5,6,7};
	int* pint = test2;

	cout << "*test2: " << *pint << endl;
	cout << "*(test2+1): " << *(pint + 1) << endl;
	cout << "*(test2+2): " << *(pint + 2) << endl;

	cout << "test2[0]: " << pint[0] << endl;
	cout << "test2[1]: " << pint[1] << endl;
	cout << "test2[2]: " << pint[2] << endl;*/

	char strA[256] = "HELLO";
	char strB[256] = "HELLO";

	int flag{};

	for (size_t i = 0; i < 256; ++i)
	{
		if (strA[i] != strB[i])
		{
			flag = 1;
			break;
		}
	}

	if (flag == 1)
		cout << "다르다" << endl;
	else
		cout << "같다" << endl;
}