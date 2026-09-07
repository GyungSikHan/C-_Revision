#include <iostream>
using namespace std;

const int MAX = 987654321;
int map[5][5]
{
	0,0,2,4,0,
	3,0,6,0,2,
	0,0,0,1,0,
	10,0,0,0,0,
	0,0,0,8,0
};
bool visited[5]{};
pair<int, string> ret = make_pair(MAX, "");

int ChangeIndex(char c)
{
	switch (c)
	{
	case 'T':
		return 0;
	case 'G':
		return 1;
	case 'H':
		return 2;
	case 'B':
		return 3;
	case 'K':
		return 4;
	}
	return -1;
}

char ChangeChar(int a)
{
	switch (a)
	{
	case 0:
		return 'T';
	case 1:
		return 'G';
	case 2:
		return 'H';
	case 3:
		return 'B';
	case 4:
		return 'K';
	}

	return -1;
}

void DFS(int start, const int end, string str, int sum)
{
	if (start == end)
	{
		if (ret.first > sum)
		{
			ret.first = sum;
			ret.second = str;
		}
		return;
	}

	for (int i = 0; i < 4; ++i)
	{
		if (map[start][i] == 0 || visited[i] == true)
			continue;
		
		visited[i] = true;
		DFS(i, end, str + ChangeChar(i), sum + map[start][i]);
		visited[i] = false;
	}
}


int main()
{
	char c1{}, c2{};
	cin >> c1 >> c2;
	
	int start = ChangeIndex(c1);
	int end = ChangeIndex(c2);
	string str{};
	str += c1;
	DFS(start, end, str, 0);

	if(ret.first == MAX)
		cout << "impossible";
	else
		cout<<ret.first << ":" << ret.second;
}