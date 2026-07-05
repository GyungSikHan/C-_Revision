#include <iostream>
using namespace std;

int map[6][6]
{
	{0,1,1,0,0,0},
	{0,0,0,1,1,1},
	{0,0,0,0,0,1},
	{0,0,0,0,0,0},
	{0,0,0,0,0,0},
	{0,0,0,0,0,0},
};

char value[6] = {'E','A','U','R','Q','Y'};

struct Node
{
	int num;
	int level;
};

Node queue[7]{};
int head = 0;
int tail = 1;

int main()
{
	while (head != tail)
	{
		Node now = queue[head];
		cout << value[now.num] << endl;
		cout << "-----------------" << endl;

		for (int i = 0; i < 6; ++i)
		{
			if (map[now.num][i] == 1)
			{
				queue[tail] = {i, now.level+1};
				tail++;
			}
		}
		head++;
	}	
}