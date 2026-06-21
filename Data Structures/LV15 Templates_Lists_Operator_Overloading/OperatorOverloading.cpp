#include <iostream>
using namespace std;

struct Point
{
	int x, y;

	Point operator+(Point other)
	{
		Point ret;
		ret.x = x + other.x;
		ret.y = y + other.y;
		return ret;
	}
	Point operator-(Point other)
	{
		Point ret;
		ret.x = x - other.x;
		ret.y = y - other.y;
		return ret;
	}
	Point operator*(Point other)
	{
		Point ret;
		ret.x = x * other.x;
		ret.y = y * other.y;
		return ret;
	}
	Point operator/(Point other)
	{
		Point ret;
		ret.x = x / other.x;
		ret.y = y / other.y;
		return ret;
	}
	Point operator%(Point other)
	{
		Point ret;
		ret.x = x % other.x;
		ret.y = y % other.y;
		return ret;
	}
	bool operator<(Point other)
	{
		return (x < other.x && y < other.y);
	}
	bool operator>(Point other)
	{
		return (x > other.x && y > other.y);
	}
	bool operator<=(Point other)
	{
		return (x <= other.x && y <= other.y);
	}
	bool operator>=(Point other)
	{
		return (x >= other.x && y >= other.y);
	}
};

int main()
{
	Point p1{ 1,1 };
	Point p2{ 2,2 };

	Point p3 = p1 - p2;
	Point p4 = p1 + p2;

	if (p1 < p2)
		cout << "p2가 p1보다 큼" << endl;
}