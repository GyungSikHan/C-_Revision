#include <iostream>

using namespace std;

int n{};
char arr[4]{ 'B','I','A','H' };
bool visited[4]{};

int DFS(int cnt, int idx)
{
	if (idx == 4)
		idx = 0;
	if (cnt == n && visited[idx] == false)
	{
		cout << arr[idx] << " ";
		visited[idx] = true;
		return idx+1;
	}
	int index{};
	if (visited[idx] == true)
		index = DFS(cnt, idx + 1);
	else
		index = DFS(cnt+1, idx + 1);

	return index;
}
int main()
{
	cin >> n;
	int count{};
	int idx{};
	while (count != 4)
	{
		idx = DFS(1,idx);
		count++;
	}
}