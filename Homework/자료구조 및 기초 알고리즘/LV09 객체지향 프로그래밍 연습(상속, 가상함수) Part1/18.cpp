#include <iostream>
using namespace std;

class Transport
{
public:
	Transport():price(){}
	Transport(const int price):price(price){}
	virtual ~Transport(){}
	virtual int CalculateFare()
	{
		return price;
	}

private:
	int price;
};

class Taxi : public Transport
{
public:
	Taxi():Transport(),miter(){}
	Taxi(const int miter) :Transport(1000), miter(miter) {}
	~Taxi() {}
	int CalculateFare()
	{
		return Transport::CalculateFare() * miter;
	}

private:
	int miter;
};

class Bus : public Transport
{
public:
	Bus() :Transport(), stations() {}
	Bus(const int stations) :Transport(1500), stations(stations) {}
	~Bus() {}
	int CalculateFare()
	{
		return Transport::CalculateFare();
	}

private:
	int stations;
};

int main()
{
	Taxi taxi(5); Bus bus(5);
	Transport* transports[] = { &taxi, &bus };
	for (int i = 0; i < 2; ++i)
		std::cout << transports[i]->CalculateFare() << std::endl;

}