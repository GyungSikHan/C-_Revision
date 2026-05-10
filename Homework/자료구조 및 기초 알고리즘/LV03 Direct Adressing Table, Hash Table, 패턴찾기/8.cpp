#include <iostream>
using namespace std;

bool IsPattern(const int* apt, const int* family)
{
	for (int i = 0; i < 3; ++i)
	{
		if (apt[i] != family[i])
			return false;
	}

	return true;
}

int main()
{
	int apt[5][3]
	{
		15,2,6,
		7,8,9,
		10,1,3,
		4,6,9,
		15,18,17
	};
	
	int family[3]{};
	for (int i = 0; i < 3; ++i)
		cin >> family[i];

	for (int i = 0; i < 5; ++i)
	{
		if (IsPattern(apt[i],family))
		{
			cout << i+1 << "층";
			break;
		}
	}

}