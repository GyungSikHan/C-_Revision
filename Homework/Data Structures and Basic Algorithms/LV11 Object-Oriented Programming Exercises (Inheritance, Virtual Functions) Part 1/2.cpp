#include <iostream>
using namespace std;

class Shape
{
public:
	Shape(){}
	virtual void Area(){}
	virtual ~Shape(){}
};

class Circle : public Shape
{
public:
	Circle(float r)
	{
		this->r = r;
	}
	void Area() override
	{
		cout << r * r * 3.14 << endl;
	}
	~Circle() override {}
private:
	float r;
};

class Rectangle : public Shape
{
public:
	Rectangle(float l1, float l2)
	{
		len[0] = l1;
		len[1] = l2;
	}
	void Area() override
	{
		cout << len[0] * len[1] << endl;
	}
	~Rectangle() override {}
private:
	int len[2];
};

int main()
{
	Circle c(3.0);
	Rectangle r(4.0, 2.0);

	Shape* s[2]{ &c, &r };

	for (int i = 0; i < 2; ++i)
	{
		s[i]->Area();
	}
}