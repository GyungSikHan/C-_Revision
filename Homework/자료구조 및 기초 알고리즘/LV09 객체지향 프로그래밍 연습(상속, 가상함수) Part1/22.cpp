#include <iostream>
using namespace std;

class Shape
{
public:
	Shape() {}
	virtual ~Shape() {}
	virtual int Area() = 0;
	virtual int Perimeter() = 0;
};

class Circle : public Shape
{
public:
	Circle() :r() {}
	Circle(const int r)
		:r(r) {}

	int Area() override
	{
		return r * r * 3.14;
	}
	int Perimeter() override
	{
		return 2 * r * 3.14;
	}
private:
	int r;
};

class Rectangle : public Shape
{
public:
	Rectangle() :width() , height(){}
	Rectangle(const int width, const int height)
		:width(width),height(height){}

	int Area() override
	{
		return width * height;
	}
	int Perimeter() override
	{
		return (width+height)*2;
	}
private:
	int width;
	int height;
};

class Triangle : public Shape
{
public:
	Triangle() :side() {}
	Triangle(const int side1, const int side2, const int side3)
	{
		side[0] = side1;
		side[1] = side2;
		side[2] = side3;
	}

	int Area() override
	{
		int s = (side[0] + side[1] + side[2]) / 2;
		int area = (int)std::sqrt(s * (s - side[0]) * (s - side[1]) * (s - side[2]));
		return area;
	}
	int Perimeter() override
	{
		int perimeter{};
		for (int i = 0; i < 3; ++i)
			perimeter += side[i];

		return perimeter;
	}
private:
	int side[3];
};

int main()
{
	Rectangle r(4, 5);
	Circle c(3);
	Triangle t(3, 4, 5);
	Shape* shapes[] = { &r, &c, &t };
	for (int i = 0; i < 3; ++i) {
		std::cout << "Area: " << shapes[i]->Area() << std::endl;
		std::cout << "Perimeter: " << shapes[i]->Perimeter() << std::endl;
	}
}