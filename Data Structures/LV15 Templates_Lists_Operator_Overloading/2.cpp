#include <iostream>
using namespace std;

template <typename T>
class Vector2
{
public:
	Vector2(T x_, T y_):x(x_), y(y_){}

	bool operator==(const Vector2& other) const
	{
		return (x == other.x && y == other.y);
	}
	bool operator!=(const Vector2& other) const
	{
		return (x != other.x && y != other.y);
	}
	Vector2& operator+(const Vector2& other)
	{
		Vector2* temp = new Vector2(x+other.x, y+other.y);
		return *temp;
	}
	Vector2& operator-(const Vector2& other)
	{
		Vector2* temp = new Vector2(x - other.x, y - other.y);
		return *temp;
	}
	Vector2& operator*(const Vector2& other)
	{
		Vector2* temp = new Vector2(x * other.x, y * other.y);
		return *temp;
	}
	Vector2& operator/(const Vector2& other)
	{
		Vector2* temp = new Vector2(x / other.x, y / other.y);
		return *temp;
	}
	void operator+=(const Vector2& other)
	{
		x += other.x;
		y += other.y;
	}
	void operator-=(const Vector2& other)
	{
		x -= other.x;
		y -= other.y;
	}
	void operator*=(const Vector2& other)
	{
		x *= other.x;
		y *= other.y;
	}
	void operator/=(const Vector2& other)
	{
		x /= other.x;
		y /= other.y;
	}
	bool operator<(const Vector2& other)
	{
		return (x < other.x && y < other.y);
	}
	bool operator>(const Vector2& other)
	{
		return (x > other.x && y > other.y);
	}
	bool operator<=(const Vector2& other)
	{
		return (x <= other.x && y <= other.y);
	}
	bool operator>=(const Vector2& other)
	{
		return (x >= other.x && y >= other.y);
	}
	

private:
	T x;
	T y;
};

int main()
{
	Vector2 v(1.0, 2.0);
	Vector2 v2(3.0, 25.0);
	Vector2 v3 = v+v2;
}