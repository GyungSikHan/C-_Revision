#include <iostream>
using namespace std;

class Robot
{
public:
	Robot():name{} {}
	Robot(const char* name)
	{
		strcpy_s(this->name, sizeof(this->name), name);
	}
	virtual ~Robot(){}
	virtual void Move() { cout << name<<" moves "; }
	virtual void Work() { cout << name << " "; }
protected:
	char name[256];
};

class CleaningRobot : public Robot
{
public:
	CleaningRobot(){}
	CleaningRobot(const char* name)
		:Robot(name){}
	~CleaningRobot() override{}

	void Move() override
	{
		Robot::Move();
		cout << "slowly" << endl;
	}
	void Work() override
	{
		Robot::Work();
		cout << "cleans floor" << endl;
	}
};

class DeliveryRobot : public Robot
{
public:
	DeliveryRobot() {}
	DeliveryRobot(const char* name)
		:Robot(name) {}
	~DeliveryRobot() override {}

	void Move() override
	{
		Robot::Move();
		cout << "fast" << endl;
	}
	void Work() override
	{
		Robot::Work();
		cout << "delivers package" << endl;
	}
};

int main()
{
	CleaningRobot cr("Roomba"); DeliveryRobot dr("DeliveryBot");
	Robot* robots[] = { &cr, &dr };
	for (int i = 0; i < 2; ++i) {
		robots[i]->Move();
		robots[i]->Work();
	}

}