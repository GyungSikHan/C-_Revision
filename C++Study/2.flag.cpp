#include <iostream>

using namespace std;

int main()
{
	int vec[7] = { 5,6,7,1,2,7,8 };
	int flag{};

	for (int i = 0; i < 7; i++)
	{
		if (vec[i] == 7)
		{
			flag = 1;
			break;
		}
	}

	if (flag == 1)
	{
		cout << "발견" << std::endl;
	}
	else
	{
		cout << "미발견" << std::endl;
	}
	return 0;
}