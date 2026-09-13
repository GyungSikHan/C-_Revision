#include <iostream>
#include <vector>
using namespace std;
const int length = 7;
int map[length]{ 15,20,45,22,55,16,45 };
string c;
bool visited[length]{};
int k{};
int ret = -1;

void eraseData(int data)
{
	visited[data] = !visited[data];
}
vector<int> v;
void Solution(int level, int sum)
{
	if (level == c.size() - k)
	{
		/*for (int i = 0; i < v.size(); ++i)
		{
			cout << v[i] << " ";
		}
		cout << endl;
		cout << sum << endl << endl;*/
		if (sum % 2 == 0)
			return;
		ret = max(ret, sum);
		return;
	}

	for (int i = 0; i < c.size(); ++i)
	{
		if (visited[i] == true)
			continue;

		visited[i] = true;
		//v.push_back(map[c[i] - 'a']);
		Solution(level + 1, sum + map[c[i] - 'a']);
		visited[i] = false;
		//v.pop_back();

	}
}

int main()
{
	cin >> c;
	cin >> k;
	Solution(0, 0);
	cout << ret;
}