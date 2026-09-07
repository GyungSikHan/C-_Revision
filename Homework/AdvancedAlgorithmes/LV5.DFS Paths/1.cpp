#include <iostream>

using namespace std;

const int length = 3;
char arr[length]{};
int visited[26]{};

void dfs(int level, string s)
{
	if (level == 3)
	{
		cout << s << endl;
		return;
	}

	for (int i = 0; i < length; ++i)
	{
		if (visited[arr[i] - 'A'] == 1)
			continue;

		visited[arr[i] - 'A'] = 1;
		dfs(level + 1, s + arr[i]);
		visited[arr[i] - 'A'] = 0;
	}
}

int main()
{
	for (int i = 0; i < length; ++i)
		cin >> arr[i];
	dfs(0, "");
}