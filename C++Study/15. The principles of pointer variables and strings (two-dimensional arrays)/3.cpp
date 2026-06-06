#include <iostream>
using namespace std;

//문자열 길이 구하는 함수
//int strlen(char* str)
//{
//	int len{};
//	int i{};
//	while (str[i] != '\0')
//	{
//		len++;
//		i++;
//	}
//
//	return len;
//}
int main()
{
	char str[3][10]{ "abc", "dabc", "badfe" };

	for (int i = 0; i < 3; ++i)
	{
		cout << "str length = " << strlen(str[i]) << endl;
	}
}