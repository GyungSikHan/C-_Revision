#include <iostream>
using namespace std;

class Shape
{
public:
	Shape(){}
	virtual ~Shape(){}
	virtual double Area() = 0;
};

class Circle : public Shape
{
public:
	Circle():r(){}
	Circle(const double r)
		:r(r){}

	double Area() override
	{
		return 2 * r * 3.14;
	}

private:
	double r;
};

class Square : public Shape
{
public:
	Square() :side() {}
	Square(const double side)
		:side(side) {}

	double Area() override
	{
		return side*side;
	}

private:
	double side;
};

int main()
{
	Circle c(5.0);
	Square s(4.0);
	Shape* shapes[] = { &c, &s };
	for (int i = 0; i < 2; ++i)
		std::cout << shapes[i]->Area() << std::endl;

}