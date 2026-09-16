#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int maxPrice = 10000;
struct Menu
{
	int price{};
	int point{};
};
vector<Menu> menu
{
	{500, 30},
	{ 300,40 },
	{ 700,10 },
	{ 400,20 },
	{ 600,30 }
};
vector<bool> visited(5, false);
int n{};
int ret{};

void DFS(int count, int totalCost, int sumPoint)
{
	if (count == n)
	{
		int num = maxPrice / totalCost;
		ret = max(ret, sumPoint * num);
		return;
	}

	for (int i = 0; i < n; ++i)
	{
		if (visited[i] == true)
			continue;

		visited[i] = true;
		DFS(count + 1, totalCost+menu[i].price, sumPoint+menu[i].point);
		visited[i] = false;
	}
}

int main()
{
	cin >> n;
	sort(menu.begin(),menu.end(),[](Menu a, Menu b)
	{
			if (a.price == b.price)
				return a.point < b.point;
			return a.price < b.price;
	});
	DFS(0, 0, 0);

	cout << ret;
}