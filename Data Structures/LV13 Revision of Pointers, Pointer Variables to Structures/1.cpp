#include <iostream>
using namespace std;

struct Vector2
{
	int x;
	int y;
};

int main()
{
	Vector2 p1;
	Vector2* vp = &p1;

	(*vp).x = 100;
	(*vp).y = 100;

	vp->x = 100;
	vp->y = 100;


}