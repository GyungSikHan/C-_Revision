#include <iostream>
using namespace std;

int main()
{
	string text{};
	string command{};
	int index{};

	cin >> text>>index>>command;

	bool bFlag{};
	for (int i = 0; i < command.size(); ++i)
	{
		if (bFlag)
			break;
		char c = command.at(i);
		switch (c)
		{
		case 'L':
			index--;
			break;
		case 'R':
			index++;
			break;
		case 'D':
			bFlag = true;
			break;
		}
	}

	cout << index;
}