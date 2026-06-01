#include <iostream>
using namespace std;

class IDrawable
{
public:
	IDrawable() {}
	virtual ~IDrawable() {};
	virtual void Draw() = 0;
};

class Circle : public IDrawable
{
public:
	Circle(int r): r(r){}
	void Draw() override
	{
		cout << "반지름 " << r << " 원 그리기" << endl;
	}
	~Circle()override{}
private:
	int r;
};

class Rectangle : public IDrawable
{
public:
	Rectangle(int w, int h) : w(w),h(h) {}
	void Draw() override
	{
		cout << "높이 " << h << " 밑변 " << w << " 사각형 그리기" << endl;
	}
	~Rectangle() override{}
private:
	int w;
	int h;
};

int main()
{
	Circle c(5); Rectangle r(4, 3);
	IDrawable* drawables[] = { &c, &r };
	for (int i = 0; i < 2; ++i)
		drawables[i]->Draw();

}