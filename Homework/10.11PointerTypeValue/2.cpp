#include <iostream>

using  namespace  std;
//main함수에서는 getChar를 호출하고, getChar에서 return받은 값을 출력, getChar에서는 문자 2개를 입력 받고, 아스키코드값이 더 큰 문자를 return

char GetChar(char* a, char* b)
{
	if (*a < *b)
		return *b;
	return *a;
}

int main()
{
	char a{}, b{};
	cin >> a >> b;

	cout << GetChar(&a, &b) << endl;
}