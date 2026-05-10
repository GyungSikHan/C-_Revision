#include <iostream>
using namespace std;

int Count(const char* cardList)
{
	int idx{};
	int count{};
	int ret[256]{};

	while (cardList[idx] != '\0')
	{
		idx++;
		ret[cardList[idx]]++;
	}

	for (int i = 'A'; i < 'Z'; ++i)
	{
		if (ret[i])
			count++;
	}

	return count;
}

int main()
{
	char cardList[256]{};
	cin >> cardList;

	cout << Count(cardList) << "개" << endl;
}