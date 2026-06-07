#include <iostream>
using namespace std;

class Delivery
{
public:
	Delivery():price(3000){}
	virtual int Calculate() = 0;
	virtual void GetInfo() = 0;

protected:
	int price;
};

class StandardDelivery : public Delivery
{
public:
	int Calculate() override
	{
		return price;
	}
	void GetInfo() override
	{
		cout << "일반 배송" << endl;
	}
};

class ExpressDelivery : public Delivery
{
public:
	ExpressDelivery(int miter):distance(miter){}
	int Calculate() override
	{
		
		return price+(distance*500);
	}
	void GetInfo() override
	{
		cout << "특별 배송, 거리당 500원" << endl;
	}

private:
	int distance;
};

int main()
{
	StandardDelivery std; ExpressDelivery exp(10);
	Delivery* deliveries[] = { &std, &exp };
	for (int i = 0; i < 2; ++i) {
		deliveries[i]->GetInfo();
		std::cout << deliveries[i]->Calculate() << std::endl;
	}
}