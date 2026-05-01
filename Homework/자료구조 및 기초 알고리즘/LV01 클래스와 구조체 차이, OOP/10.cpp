#include <iostream>
using namespace std;

class Wheel
{
public:
	Wheel():wheelSize(),wheelRadius() {}
	~Wheel(){}

	void SetWheelSize(int size)
	{
		wheelSize = size;
	}
	void WheelRadius(int radius)
	{
		wheelRadius = radius;
	}
	void PrintData()
	{
		cout << "size " << wheelSize << "inch radius " << wheelRadius << "cm" << endl;
	}
private:
	int wheelSize;
	int wheelRadius;
};

class Car
{
public:
	Car() :name{}, wheels{}, carSpeed(), fuel() {}
	Car(const char* name) : wheels{}, carSpeed(), fuel()
	{
		strcpy_s(this->name, sizeof(this->name), name);
	}
	~Car(){}

	void SetCarSpeed(int speed)
	{
		carSpeed = speed;
	}
	void SetFuel(int fuel)
	{
		this->fuel = fuel;
	}

	void AddWheels(Wheel* wheels, int length = 4)
	{
		for (int i = 0; i < length; ++i)
		{
			this->wheels[i] = wheels[i];
		}
	}
	void PrintData()
	{
		cout << name << endl;
		cout << "speed: " << carSpeed << "km" << endl;
		cout << "fuel: " << fuel << "l" << endl;
		for (int i = 0; i < 4; ++i)
		{
			cout << "wheel[" << i << "]: ";
			wheels[i].PrintData();
		}
		
	}
private:
	char name[256];
	Wheel wheels[4];
	int carSpeed;
	int fuel;
};

int main()
{
	Wheel ferarilWheel[4];
	for (int i = 0; i < 4; ++i)
	{
		ferarilWheel[i].SetWheelSize(5);
		ferarilWheel[i].WheelRadius(20);
	}
	Wheel avanteWheel[4];
	for (int i = 0; i < 4; ++i)
	{
		avanteWheel[i].SetWheelSize(3);
		avanteWheel[i].WheelRadius(20);
	}

	Car feraril = Car("feraril");
	feraril.SetCarSpeed(200);
	feraril.SetFuel(100);
	feraril.AddWheels(ferarilWheel);

	Car avante = Car("avante");
	avante.SetCarSpeed(100);
	avante.SetFuel(50);
	avante.AddWheels(avanteWheel);

	feraril.PrintData();
	avante.PrintData();
}