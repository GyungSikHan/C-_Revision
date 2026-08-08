#include <iostream>
using namespace std;

int map[9]{ 1,2,3,3,5,1,0,1,3 };

int main()
{
	int n{};

	cin >> n;


	int ret = 987654321;
	for (int i = 0; i <= 9-n; ++i)
	{
		int sum{};
		for (int j = 0; j < n; ++j)
			sum += map[i+j];
		
		ret = std::min(ret, sum);
	}

	cout << ret;
}