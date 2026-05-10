//Direct Addres Table
#include <iostream>
using namespace std;

int main()
{
	int bucket[256]{};
	char str[7] = "ADBFAD";

	for (int i = 0; i < 6; ++i)
	{
		int idx = str[i];
		bucket[idx]++;
	}

	int count{};
	for (int i = 'A'; i < 'Z'; ++i)
	{
		//cout << (char)i << " : " << bucket[i] << endl;
		if (bucket[i] != 0)
		{
			for (int j = 0; j < bucket[i]; ++j)
			{
				cout << (char)i;
			}
		}
	}

}