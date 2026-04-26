#include <iostream>
using namespace std;

class Circle
{
public:
	Circle() {}
	~Circle() {}

	size_t StrLen(const char* str)
	{
		return strlen(str);
	}

	void CopyStr(char* str, const char* str2)
	{
		size_t len = strlen(str2);
		for (int i = 0; i < len; ++i)
		{
			str[i] = str2[i];
		}
		str[len] = '\0';
	}

	void SetRadius(int radius)
	{
		this->radius = radius;
	}
	void SetColor(const char* color)
	{
		CopyStr(this->color, color);
	}

	void SetFilled(const char* filled)
	{
		CopyStr(this->filled, filled);
	}

	void SetOpacity(const float opacity)
	{
		this->opacity = opacity;
	}

	float CalculationArea()
	{
		return radius * radius * PI;
	}

	float CalculationCircumference()
	{
		return 2 * radius * PI;
	}

	void Print()
	{
		cout << "Circle" << endl;
		cout << "Radius: " << radius << endl;
		cout << "Color: " << color << endl;
		cout << "Filled: " << filled << endl;
		cout << "Opacity: " << opacity << endl;
		cout << "Area: " << (area = CalculationArea()) << endl;
		cout << "Circumference: " << (circumference = CalculationCircumference()) << endl;
	}

private:
	float PI = 3.14;
	int radius;
	char color[256];
	char filled[256];
	float opacity;
	float area;
	float circumference;
};

int main()
{
	Circle circle;
	circle.SetRadius(5);
	circle.SetColor("Red");
	circle.SetFilled("Yse");
	circle.SetOpacity(0.75);

	circle.Print();
}