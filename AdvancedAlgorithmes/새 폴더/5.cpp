#include <iostream>
#include <vector>

using namespace std;

vector<int> memo;

long long fib_memo(int n)
{
	if (n <= 1)
		return n;

	if (memo[n] != 0)
		return memo[n];

	int left = fib_memo(n-1);
	int right = fib_memo(n-2);
	memo[n] = left + right;

	return memo[n];
}

long long fib_dp(int n)
{
	vector<long long> dp(n + 1);
	dp[0] = 0;
	dp[1] = 1;
	
	for (int i = 2; i <= n; ++i)
		dp[i] = dp[i - 1] + dp[i - 2];

	return dp[n];
}

int main()
{
	//int prev = fib(4);

	int n = 4;
	memo.resize(n + 1);
	long long ans = fib_memo(n);
	cout << ans << endl;
	ans = fib_memo(2);
	cout << ans <<endl;

	int dp = fib_dp(n);
	cout << dp << endl;
}