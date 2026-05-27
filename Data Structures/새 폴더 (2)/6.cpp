#include <iostream>
using namespace std;

bool CheckBT(char* str)
{
	for (int i = 0; i < 4; ++i)
	{
		if (str[i] == 'B' || str[i] == 'T')
			return true;
	}
	return false;
}

int Solve(char* str, int len, char* ret)
{
	
	if (len == 4)
	{
		if (CheckBT(ret))
		{
			cout << ret << endl;
			return 1;
		}
		return 0;
	}

	int sum{};
	for (int i = 0; i < 4; ++i)
	{
		if (len > 0)
		{
			if ((ret[len - 1] == 'B' && str[i] == 'T') )
				continue;
			if((ret[len - 1] == 'T' && str[i] == 'B'))
				continue;
		}
		ret[len] = str[i];
		sum+=Solve(str, len + 1, ret);
		ret[len] = '\0';
	}

	return sum;
}

int main()
{
	char str[5]{};
	char ret[5]{};
	cin >> str;
	cout<<Solve(str, 0, ret);

}