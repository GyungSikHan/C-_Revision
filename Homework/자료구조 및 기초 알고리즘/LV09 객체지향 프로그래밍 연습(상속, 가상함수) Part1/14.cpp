#include<iostream>
using namespace std;

class Vehicle
{
public:
	Vehicle(){}
	~Vehicle(){}

	virtual void StartEngine()
	{
		cout << "Start Engine" << endl;
	}
	virtual void Drive()
	{
		cout << "Drive" << endl;
	}
	virtual void StopEngine()
	{
		cout << "Stop Engine" << endl;
	}
};

class Car : public Vehicle
{
public:
	void StartEngine() override
	{
		cout << "Car ";
		Vehicle::StartEngine();
	}
	void Drive() override
	{
		cout << "Car ";
		Vehicle::Drive();
	}
	void StopEngine() override
	{
		cout << "Car";
		Vehicle::StopEngine();
	}
};

class Motorcycle : public Vehicle
{
public:
	void StartEngine() override
	{
		cout << "Motorcycle ";
		Vehicle::StartEngine();
	}
	void Drive() override
	{
		cout << "Motorcycle ";
		Vehicle::Drive();
	}
	void StopEngine() override
	{
		cout << "Motorcycle";
		Vehicle::StopEngine();
	}
};

int main()
{
	Car c; Motorcycle m;
	Vehicle* vehicles[] = { &c, &m };
	for (int i = 0; i < 2; ++i) {
		vehicles[i]->StartEngine();
		vehicles[i]->Drive();
		vehicles[i]->StopEngine();
	}

}