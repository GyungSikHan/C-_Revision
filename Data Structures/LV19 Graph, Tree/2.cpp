#include <iostream>
using namespace std;

void InputData(int* map)
{
	for (int i = 0; i < 4; ++i)
		cin >> map[i];
}
void CountData(const int* map, int* count)
{
	for (int i= 0; i < 4; ++i)
		if (map[i]== 1)
			count++;
}

int main()
{
	int map[4][4]{};
	int count[4];
	for (int i = 0; i < 4; ++i)
		InputData(map[i]);

	for (int i = 0; i < 4; ++i)
		CountData(map[i], &(count[i]));


	int ret = -1;
	int idx{};
	for (int i = 0; i < 4; ++i)
	{
		if (ret < count[i])
		{
			idx = i;
			ret = count[i];
		}
	}

	cout << (char)('A' + idx);
}