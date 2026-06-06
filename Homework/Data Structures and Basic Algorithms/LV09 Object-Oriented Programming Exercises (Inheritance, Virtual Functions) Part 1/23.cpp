#include <iostream>
using namespace std;

class Device
{
public:
	Device():name{}, bPower(false){}
	Device(const char* name)
		:bPower(false)
	{
		strcpy_s(this->name, sizeof(this->name), name);
	}
	virtual ~Device(){}

	virtual void PowerOn() { bPower = true; }
	virtual void ShowInfo() = 0;
	virtual void PowerOff() { bPower = false; }
protected:
	char name[256];
	bool bPower;
};

class Smartphone : public Device
{
public:
	Smartphone(const char* name)
		:Device(name){}
	void PowerOn() override
	{
		Device::PowerOn();
	}
	void PowerOff() override
	{
		Device::PowerOff();
	}
	void ShowInfo() override
	{
		cout << name << " Power "<<(bPower ? "On":"Off") << endl;
	}
};

class SmartWatch : public Device
{
public:
	SmartWatch(const char* name)
		:Device(name) {}
	void PowerOn() override
	{
		Device::PowerOn();
	}
	void ShowInfo() override
	{
		cout << name << " Power " << (bPower ? "On" : "Off") << endl;
	}
};

int main()
{
	Smartphone sp("Galaxy");
	SmartWatch sw("Apple Watch");
	Device* devices[] = { &sp, &sw };
	for (int i = 0; i < 2; ++i) {
		devices[i]->PowerOn();
		devices[i]->ShowInfo();
		devices[i]->PowerOff();
	}

}