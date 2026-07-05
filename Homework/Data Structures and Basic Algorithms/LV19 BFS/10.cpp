#include <iostream>
using namespace std;

int arr[11]{ 0,3,1,2,1,3,2,1,2,1,0 };

void DFS(int n)
{
	if (arr[n] == 0)
	{
		cout << "도착 ";
		return;
	}

	cout << arr[n]<<" ";
	DFS(n + arr[n]);
	cout << arr[n]<<" ";
}

int main()
{
	int n{};

	cin >> n;

	cout << "시작 ";
	DFS(n);
	cout << "시작 ";
}