#include <iostream>
using namespace std;

int map[4][4]
{
	{0,10,2,40},
	{0,0,2,5},
	{0,3,0,30},
	{0,0,0,0}
};

struct Node
{
	int num;
	int sum;
	int used[4];
};

Node qu[20] = {{0,0,{1}}};
int head = 0, tail = 1;
int minValue = 2100000000;

int main()
{
	while (head != tail)
	{
		Node now = qu[head++];
		if (now.num == 3 && minValue > now.sum)
			minValue = now.sum;

		for (int i = 0; i < 4; ++i)
		{
			if (map[now.num][i] != 0 && now.used[i] == 0)
			{
				qu[tail] = now;
				qu[tail].num = i;
				qu[tail].sum = now.sum+map[now.num][i];
				qu[tail].used[i] = 1;

				tail++;
			}
		}
	}
	cout << minValue;
}