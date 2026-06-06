#include <iostream> 
using namespace std;

class SmartDevice
{
public:
	virtual void Execute(const char* command) { cout << command << endl; }
};

class SmartLight : public SmartDevice
{
public:
	void Execute(const char* command) override
	{
		cout << command << endl;
	}
};

class SmartSpeaker : public SmartDevice
{
public:
	void Execute(const char* command) override
	{
		cout << command << endl;
	}
};

int main()
{
	SmartLight sl; 
	SmartSpeaker ss;
	SmartDevice* devices[] = { &sl, &ss };
	for (int i = 0; i < 2; ++i)
		devices[i]->Execute("turn on");

}