#include <iostream>

char name[5] = "ABCD";
int data[4][4]
{
	0,10,60,0,
	10,0,20,40,
	60,20,0,50,
	0,40,50,0
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

void DFS(int level, int now, int sum)
{
	if (name[now] == 'D')
	{
		count++;
		std::cout << history <<" "<<sum << std::endl;
	}

	for (int i = 0; i < 4; ++i)
	{
		if (data[now][i] > 1)
		{
			if (IsPossible(level,i) == 1)
			{
				history[level + 1] = name[i];
				DFS(level+1,i,sum+data[now][i]);
				history[level + 1] = '\0';
			}
		}
	}
}

int main()
{
	history[0] = name[0];
	DFS(0,0,0);
}