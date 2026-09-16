#include <iostream>
#include <vector>

using namespace std;

string oper[5]{ "!!","#", "$","&","^" };
int n[3]{};
int cnt{};

int Operator(int data1, int data2, string op)
{
	if (op == "!!")
		return data1 + data2 + data2;
	if (op == "#")
		return data1 - data2 - data2;
	if (op == "$")
		return data1 + 10;
	if (op == "&")
		return data1 + pow(data2, 2);

	return 0;
}

void Solution(vector<int>& v, int size)
{
	if (size == 2)
	{
		int ret = Operator(n[0], n[1], oper[v[0]]);
		ret = Operator(ret, n[2], oper[v[1]]);
		//cout << n[0] << oper[v[0]]<< n[1]<<oper[v[1]]<<n[2]<<" = " <<ret << endl;
		if (20 < ret)
			cnt++;
		return;
	}

	for (int i = 0; i < 5; ++i)
	{
		v.push_back(i);
		Solution(v,size+1);
		v.pop_back();
	}
}

int main()
{
	for (int i = 0; i < 3; ++i)
		cin >> n[i];

	vector<int> v;
	Solution(v, 0);
	cout << cnt;
}