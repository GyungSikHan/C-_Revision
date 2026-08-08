#include <iostream>
using namespace std;

const int LEN = 5;
const string mapom = "MAPOM";

void InputSTR(char* str)
{
	for (int i = 0; i < LEN; ++i)
		cin >> str[i];
}
void Swap(char* str)
{
	swap(str[1], str[3]);
}

bool Check(char* str)
{
	for (int i = 0; i < LEN; ++i)
		if (str[i] != mapom.at(i))
			return false;
	return true;
}

int main()
{
	char str[LEN][LEN]{};
	for (int i = 0; i < LEN; ++i)
		InputSTR(str[i]);

	bool ret{};
	for (int i = 0; i < LEN; ++i)
	{
		Swap(str[i]);
		ret = Check(str[i]);
		if (ret == true)
			break;
	}

	cout << (ret == true ? "yes" : "no");
}