#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Point
{
	int x, y;
};

bool compareByx(const Point& a, const Point& b)
{
	return a.x < b.x;
}

int main()
{
	vector<int>v = {5,1,9,3,7};
	//정렬
	sort(v.begin(),v.end());
	
	//검색
	auto it = find(v.begin(),v.end(), 7);
	if (it != v.end())
		cout << "found 7 at index " << (it - v.begin()) << "\n";

	reverse(v.begin(), v.end());

	for (int x : v)
		cout << x << " ";
	cout << endl;

	vector<Point> p = {{3,4},{1,9}, {2,2}};
	sort(p.begin(), p.end(), compareByx);
	sort(p.begin(), p.end(), [](const Point& a, const Point& b)
		{
			return a.y < b.y;
		});
}