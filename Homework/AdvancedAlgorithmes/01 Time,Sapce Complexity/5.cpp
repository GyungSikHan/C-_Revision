#include <iostream>
#include <vector>
using namespace std;

const string DATA = "HITSMUSIC";
int n{};
vector<string> v;
int cnt{};

int main()
{
	cin >> n;
	v.assign(n, "");

	for (int i = 0; i<n; i++)
		cin>>v[i];

	for (int i = 0; i < n-1; ++i)
	{
		for (int j = i+1; j < n; ++j)
		{
			string temp = v[i] + v[j];
			//cout << temp << endl;
			if (strcmp(temp.c_str(), DATA.c_str()) == 0)
				cnt++;
		}
	}

	cout << cnt;
}