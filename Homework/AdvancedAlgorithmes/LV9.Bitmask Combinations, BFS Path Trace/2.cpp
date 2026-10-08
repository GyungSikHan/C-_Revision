#include <iostream>

using namespace std;

const int maxCount = 10;
const int length = 4;
const char oper[length]{ '/','*','+','-' };
const int arr[length]{ 2,2,1,1 };

int currChanel{};
int goleChanel{};

int Operator(const int curr, const int data, const char c)
{
	if (c == '/')
		return (curr / data);
	if (c == '*')
		return curr * data;
	if (c == '+')
		return curr + data;

	return curr - data;
}

int dfs(int count, int curr)
{
	if (count >= maxCount)
		return INT_MAX;
	if (curr == goleChanel)
		return count;
	
	int ret = INT_MAX;
	for (int i = 0; i < length; ++i)
	{
		ret = min(ret,dfs(count + 1, Operator(curr, arr[i], oper[i])));
	}

	return ret;
}
int main()
{
	cin >> currChanel >> goleChanel;
	int ret = dfs(0, currChanel);

	if (ret == INT_MAX)
		cout << "실패";
	else
		cout << ret;
}