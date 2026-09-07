#include <iostream>
#include <vector>
using namespace std;

const int len = 4;

int Sum(const vector<int>& v, int start, int end)
{
	int sum{};
	for (int i = start; i < end; ++i)
		sum += v[i];

	return sum;
}

int main()
{
	int n{};
	cin >> n;
	vector<int> v(n,0);
	for (int i = 0; i < n; ++i)
		cin >> v[i];

	int ret = 987654321;
	for (int i = 0; i < n-len; ++i)
		ret = std::min(ret, Sum(v, i, i + len));
	
	cout << ret;
}