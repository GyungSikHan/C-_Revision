#include <iostream>
#include <variant>

using namespace std;

const int length = 4;
const int num = 3000;

int arr[length]{};
bool visited[length]{};
int cnt{};

void DFS(int count, int sum)
{
	if (count == length)
	{
		if (sum > num)
			cnt++;
		return;
	}

	for (int i = 0; i < length; ++i)
	{
		if (visited[i] == true)
			continue;
		visited[i] = true;
		DFS(count + 1, sum * 10 + arr[i]);
		visited[i] = false;
	}
}

int main()
{
	for (int i = 0; i < length; ++i)
		cin >> arr[i];
	DFS(0,0);
	cout << cnt;
}

//int main()
//{
//	int arr[4];
//
//	for (int& n : arr)
//		cin >> n;
//
//	sort(arr, arr + 4);
//
//	int cnt = 0;
//
//	do
//	{
//		int value =
//			arr[0] * 1000 +
//			arr[1] * 100 +
//			arr[2] * 10 +
//			arr[3];
//
//		if (value > 3000)
//			cnt++;
//
//	} while (next_permutation(arr, arr + 4));
//
//	cout << cnt;
//}