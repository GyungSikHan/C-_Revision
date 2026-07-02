#include <iostream> 
#include <vector>
using namespace std;

int main()
{
	int n{};
	cin >> n;

	vector<vector<int>> v(n,vector<int>(n, 0));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> v[i][j];

	vector<vector<int>> temp(n, vector<int>(n, 0));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			temp[i][j] = v[n - j - 1][i];

	v = temp;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << v[i][j]<<" ";
		}
		cout << endl;
	}
}