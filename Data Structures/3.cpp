#include <iostream>
using namespace std;

class Vector2D
{
public:
	Vector2D(float x = 0, float y = 0)
		: mX(x),mY(y)
	{
		
	}

	~Vector2D()
	{
		cout << "소멸자 호출" << endl;
	}

	Vector2D operator +(const Vector2D& other)const
	{
		return Vector2D(mX + other.mX, mY + other.mY);
	}

	Vector2D operator - (const Vector2D& other)const
	{
		return Vector2D(mX - other.mX, mY - other.mY);
	}

	Vector2D operator * (const Vector2D& other)const
	{
		return Vector2D(mX * other.mX, mY * other.mY);
	}

	void Print()
	{
		cout << "(" << mX << ", " << mY << ")" << endl;
	}

private:
	float mX;
	float mY;
};

int main()
{
	Vector2D v1(1.0f, 2.0f);
	Vector2D v2(3.0f, 4.0f);

	Vector2D v3 = v1 + v2;

	v3.Print();
}