#include <iostream>
using namespace std;

class Point
{
public:
	Point() {}
	~Point(){}

	void Print()
	{
		cout << "Point Tag: " << tag << " | Coordinates: (" << x << ", " << y << ", " << z << ")";
	}

	char tag;
	int x;
	int y;
	int z;
};

int main()
{
	Point point;
	point.tag = 'A';
	point.x = 3;
	point.y = 4;
	point.z = 7;
	point.Print();
}