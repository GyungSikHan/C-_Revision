#include <iostream>

char name[5] = "ABCD";
int data[4][4]
{
	0,1,1,0,
	1,0,1,1,
	1,1,0,1,
	0,1,1,0
};
char history[5]{};
int count{};

int IsPossible(int level, int select)
{
	for (int i = 0; i < level; ++i)
		if (history[i] == name[select])
			return 0;
	
	return 1;
}

void DFS(int level, int now)
{
	if (name[now] == 'D')
	{
		count++;
		std::cout << history << std::endl;
		return;
	}

	for (int i = 0; i < 4; ++i)
	{
		if (data[now][i] == 1)
		{
			if (IsPossible(level,i) == 1)
			{
				history[level + 1] = name[i];
				DFS(level+1,i);
				history[level + 1] = '\0';
			}
		}
	}
}

int main()
{
	history[0] = name[0];
	DFS(0,0);
}