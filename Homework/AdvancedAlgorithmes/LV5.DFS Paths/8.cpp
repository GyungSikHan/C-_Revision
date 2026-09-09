#include  <iostream>

using namespace std;

int coins[3]{ 10,40,60 };
int gold{};
int ret = 987654321;

void Solution(int data, int cnt)
{
	if (data < 0 || cnt > ret)
		return;
	if (data == 0)
	{
		ret = min(ret, cnt);
		return;
	}

	if (data >= coins[0])
		Solution(data - coins[0], cnt+1);
	if (data >= coins[1])
		Solution(data - coins[1], cnt+1);
	if (data >= coins[2])
		Solution(data - coins[2], cnt+1);

}

int main()
{
	cin >> gold;

	Solution(gold, 0);
	cout << ret;
}