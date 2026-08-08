#include<iostream>
#include <string>
using namespace std;

int P{}, N{}, ret{};

string Reverse(string str)
{
	string temp{};
	for (int i = static_cast<int>(str.size())-1; i >= 0; --i)
		temp += str[i];
	return temp;
}

int main()
{
	cin >> P >> N;
	for (int i = 0; i < N; ++i)
	{
		P *= 2;
		P = stoi(Reverse(to_string(P)));
		//cout << P << endl;
	}

	cout << P << endl;
}