#include <iostream>
using namespace std;

int main()
{
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

	//실무 표준
	//c스타일
	cout << "length = " << strlen(strA) << endl;

	if (strcmp(strA, strB) == 0)
		cout << "같음"<<endl;

	//c++ 스타일(권장)
	string str1 = "HELLO";
	string str2 = "HELLO";
	if (str1 == str2)
		cout << "같음"<<endl;

}