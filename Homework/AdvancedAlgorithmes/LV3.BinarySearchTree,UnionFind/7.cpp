#include <iostream>
#include <vector>
using namespace std;

int n{}, k{};
int cnt{}, gcnt{};
vector<int> v;
vector<char> name(100, '\0');
vector<int> group(100, 0);

void Alliance(char c1, char c2)
{
	if (group[c1 ] == 0)
		name[cnt++] = c1;
	if (group[c2 ] == 0)
		name[cnt++] = c2;

	if (group[c1 ] != 0 && group[c2 ] == 0)
		group[c2 ] = group[c1 ];
	else if (group[c2 ] != 0 && group[c1 ] == 0)
		group[c1] = group[c2];
	else if (group[c2 ] == 0 && group[c1] == 0)
	{
		gcnt++;
		group[c1] = gcnt;
		group[c2] = gcnt;
	}
	else
	{
		int g = group[c2];
		for (int i = 0; i < cnt; ++i)
		{
			if (group[name[i]] == g)
				group[name[i]] = group[c1];
		}
	}
}

int Sum(char c)
{
	int i{};
	int a = group[c];
	int sum{};
	while (name[i] != '\0')
	{
		if (group[name[i]] == a)
			sum += v[name[i] - 'A'];
		i++;
	}

	return sum;
}

void Boom(char c)
{
	int i{};
	int a = group[c];
	int sum{};
	while (name[i] != '\0')
	{
		if (group[name[i]] == a)
		{
			group[name[i]] = 0;
			n--;
		}
		i++;
	}
}

void War(char c1, char c2)
{
	int aSum =Sum(c1); 
	int bSum =Sum(c2); 

	if (aSum < bSum)
		Boom(c1);
	else
		Boom(c2);

}

int main()
{
	cin >> n;
	v.assign(n, 0);
	
	for (int i = 0; i < n; ++i)
		cin >> v[i];
	
	cin >> k;

	for (int i = 0; i < k; ++i)
	{
		string s{};
		char c1{}, c2{};

		cin >> s >> c1 >> c2;

		if (s ==  "alliance")
			Alliance(c1,c2);
		else if (s == "war")
			War(c1,c2);
	}

	cout << n;
}