#include <iostream>
using namespace std;

const int num = 4;

void Solve(char* name, int* visited, int cnt, char* str)
{
	if (cnt == 3)
	{
		cout << str << endl;
		return;
	}

	for (int i = 0; i < num; ++i)
	{
		if (visited[i])
			continue;

		visited[i] = 1;
		str[cnt] = name[i];
		Solve(name, visited, cnt + 1, str);
		visited[i] = 0;
		str[cnt] = '\0';
	}
}

int main()
{
	char name[num+1]{'\0'};
	int visited[num]{};

	for (int i = 0; i < num; ++i)
	{
		cin >> name[i];
	}

	char str[num]{};
	Solve(name, visited, 0, str);
}