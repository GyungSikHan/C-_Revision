#include <iostream>
using namespace std;

class Rectangle
{
public:
	Rectangle(){}
	~Rectangle() {}

	void SetWidth(const int width)
	{
		this->width = width;
	}
	void SetHeight(const int height)
	{
		this->height = height;
	}
	void SetColor(const char* color)
	{
		size_t len = strlen(color);
		for (int i = 0; i < len; ++i)
		{
			this->color[i] = color[i];
		}
		this->color[len] = '\0';
	}
	void SetBorder(const int border)
	{
		this->border = border;
	}

	int CalculationArea()
	{
		return width * height;
	}

	int CalculationPerimeter()
	{
		return 2 * (width + height);
	}

	void Print()
	{
		cout << "Color: " << color << ", Border: " << border << "px" << endl;
		cout << "Area: " << CalculationArea() << ", Perimter: " << CalculationPerimeter() << endl;
	}

private:
	char color[256];
	int border;
	int width;
	int height;
};

int main()
{
	Rectangle rectangle;
	rectangle.SetColor("Red");
	rectangle.SetBorder(5);
	rectangle.SetWidth(10);
	rectangle.SetHeight(10);

	rectangle.Print();
}