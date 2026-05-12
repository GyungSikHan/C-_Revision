#include "22Time.h"

#include <iostream>

Time::Time()
	:hour(),minute(),second()
{
}

Time::Time(int hour, int minute, int second)
	:hour(hour),minute(minute),second(second)
{
}

Time::~Time()
{
}

Time Time::operator+(const Time& time)
{
	int h = hour + time.GetHour();
	int m = minute + time.GetMinute();
	int s = second + time.GetSecond();
	if (s - 60 > 0)
	{
		m++;
		s -= 60;
	}
	if (m - 60 > 0)
	{
		h++;
		m -= 60;
	}

	return Time(h, m, s);
}

int Time::GetHour() const
{
	return hour;
}

int Time::GetMinute() const
{
	return minute;
}

int Time::GetSecond() const
{
	return second;
}

void Time::Print()
{
	std::cout << hour << "시 " << minute << "분 " << second << "초" << std::endl;
}
