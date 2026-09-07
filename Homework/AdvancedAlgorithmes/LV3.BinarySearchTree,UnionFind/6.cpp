#include<iostream>
#include <vector>
using namespace std;

int n{}, k{};
vector<char> v;
vector<int> group;

int parent(char c)
{
	if (group[c - '0'] == 0)
		return c - '0';

	return parent(group[c - '0']);
}

void Input(int idx, char& data)
{
	if (group[idx] == 0)
	{
		data = v[idx];
		return;
	}

	Input(group[idx], data);
}

int main()
{
	cin >> n >> k;
	v.assign(k+1, '\0');
	group.assign(k+1, 0);

	for (int i = 0; i < n; ++i)
	{
		char c1{}, c2{};

		cin >> c1 >> c2;

		if (std::isdigit(static_cast<int>(c1)) && std::isdigit(static_cast<int>(c2)))
		{
			int a = parent(c1);
			int b = parent(c2);


			group[b] = a;
			for (int j = 1; j < k+1; ++j)
			{
				if (group[i] == b)
					group[i] = a;
			}
		}
		else
		{
			int idx{};
			char temp{};
			if (std::isdigit(static_cast<int>(c1)))
			{
				temp = c2;
				idx = c1 - '0';
			}
			else
			{
				temp = c1;
				idx = c2 - '0';
			}

			v[idx] = temp;
		}
	}
	
	char temp{};
	for (int i = 1; i < k+1; ++i)
	{
		if (v[i] == '\0')
		{
			Input(i, temp);
			v[i] = temp;
		}
	}

	for (int i = 1; i < k+1 ;i++)
		cout << v[i];
}