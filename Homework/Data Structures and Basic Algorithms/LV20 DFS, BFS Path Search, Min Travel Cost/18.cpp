#include <iostream>
#include <string>

using namespace std;

const int MAX = 5;

int n{};
char arr[MAX]{};
char ret[3];
bool visited[MAX]{};
int smal = 987654321;

void DFS(int level)
{
	if (level == n)
		return;
	if (level == 3)
	{
		//cout<<ret<< endl;
		smal = std::min(smal, stoi(ret));
		return;
	}

	for (int i = 0; i < n; ++i)
	{
		if (visited[i] == false)
		{
			ret[level] = arr[i];
			visited[i] = true;
			DFS(level + 1);
			visited[i] = false;
		}
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	for (int i = 0; i < n; ++i)
	{
		if (arr[i] != '0')
		{
			ret[0] = arr[i];
			visited[i] = true;
			DFS(1);
			visited[i] = false;
			ret[0] = 0;
		}
	}

	cout << smal;
}