#pragma once

class Time
{
public:
	Time();
	Time(int hour, int minute, int second);
	~Time();

	Time operator+(const Time& time);

	int GetHour() const;
	int GetMinute() const;
	int GetSecond() const;
	void Print();
private:
	int hour;
	int minute;
	int second;
};


