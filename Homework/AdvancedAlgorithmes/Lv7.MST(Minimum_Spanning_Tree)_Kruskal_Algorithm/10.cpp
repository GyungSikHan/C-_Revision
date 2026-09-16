#include <iostream>
#include <vector>
using namespace std;

const int lenght = 3;

int map[lenght][lenght];
bool visited[lenght][lenght];
bool temp[lenght][lenght];
pair<int, int> ret{0, -987654321};
//vector<int> v;
//vector<pair<int,int>> v2;

void DFS(int data, int level)
{
	if (level == 3)
	{
		/*for (int i = 0; i < v.size(); i++)
		{
			cout << v2[i].first << " " << v2[i].second << " " << v[i] << endl;;
		}
		cout << data << endl;
		cout << endl;*/
		if (ret.second < data)
		{
			ret.first = 1;
			ret.second = data;
		}
		else if (ret.second == data)
			ret.first++;
		return;
	}

	for (int i = 0; i < lenght; ++i)
	{
		for (int j = 0; j < lenght; ++j)
		{
			if (map[i][j] == 0)
				continue;
			if (visited[i][j] == true)
				continue;
			visited[i][j] = true;
			//v.push_back(map[i][j]);
			//v2.push_back({ i,j });
			DFS(data * map[i][j], level + 1);
			if (level != 0 && level != 1)
				visited[i][j] = false;
			//v.pop_back();
			//v2.pop_back();
		}
	}
}

int main()
{
	for (int i = 0; i < lenght; ++i)
		for (int j = 0; j < lenght; ++j)
			cin >> map[i][j];

	for (int i = 0; i < lenght; ++i)
	{
		for (int j = 0; j < lenght; ++j)
		{
			if (map[i][j] == 0)
				continue;
			if (temp[i][j] == false)
			{
				//cout << i<<" "<<j << endl;
				//v.push_back(map[i][j]);
				//v2.push_back({ i,j });
				temp[i][j] = true;

				memcpy(visited, temp, sizeof(visited));
				DFS(map[i][j], 1);
				/*v.pop_back();
				v2.pop_back();
				cout << endl << endl;*/
			}
		}
	}
	cout << ret.first;
	
}