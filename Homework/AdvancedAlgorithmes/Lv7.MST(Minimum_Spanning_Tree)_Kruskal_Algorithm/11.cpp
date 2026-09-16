#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

string str{};
int arr[26]{};
void DFS(int level, string ret, int idx)
{
	if (level == 3)
	{
		cout << ret << endl;
		return;
	}

	for (int i = idx; i < str.size(); ++i)
	{
		DFS(level + 1, ret + str[i], i);
	}
}
int main()
{
	cin >> str;
	sort(str.begin(), str.end());
	str.erase(std::unique(str.begin(), str.end()), str.end());
	
	DFS(0, "", 0);
}