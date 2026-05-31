#include <iostream>
using namespace std;

class Exercise
{
public:
	Exercise(): kcal(), hour(), minute(){}

	void ChangeHourToMinute(int time)
	{
		if (time < 60)
		{
			minute = time;
			return;
		}

		hour = time / 60;
		minute = time % 60;
	}

	virtual void PrintCalories() { cout << kcal << endl; }
protected:
	int kcal;
	int hour;
	int minute;
};

class Running : public Exercise
{
public:
	Running(int time)
	{
		ChangeHourToMinute(time);
		kcal = 10;
	}
	void PrintCalories() override
	{
		int temp = kcal * hour;
		if (minute != 0)
			temp = kcal / (60 / minute);
		cout << temp << endl;
	}
};

class Cycling : public Exercise
{
public:
	Cycling(int time)
	{
		ChangeHourToMinute(time);
		kcal = 6;
	}
	void PrintCalories() override
	{
		int temp = kcal * hour;
		if (minute != 0)
			temp = kcal / (60 / minute);
		cout << temp << endl;
	}
};

int main()
{
	Running run(30);
	Cycling cyc(60);
	Exercise* logs[] = { &run, &cyc };
	for (int i = 0; i < 2; ++i)
		logs[i]->PrintCalories();

}