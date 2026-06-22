#include <iostream>
using namespace std;

bool visited[4]{};

void Solution(const int input, string ret,int count)
{
	if (input == count)
	{
		cout << ret << endl;
		return;
	}

	for (int i = 0; i < 4; ++i)
	{
		if (visited[i] == true)
			continue;

		visited[i] = true;
		ret += (char)('A' + i);
		Solution(input, ret, count + 1);
		ret.pop_back();
		visited[i] = false;
	}
}

int main()
{
	int input{};
	cin >> input;
	for (int i = 0; i < 4; ++i)
	{
		string ret{};
		ret += (char)('A' + i);
		visited[i] = true;
		Solution(input,ret, 1);
		visited[i] = false;
	}
}