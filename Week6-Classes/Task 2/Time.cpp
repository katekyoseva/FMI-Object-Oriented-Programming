#include "Time.h"
#include <iostream>

Time::Time()
{
	setHours(0);
	setMinutes(0);
	setHours(0);
}

unsigned Time::getHours() const
{
	return hours;
}

unsigned Time::getMinutes() const
{
	return minutes;
}

unsigned Time::getSeconds() const
{
	return seconds;
}

void Time::setHours(unsigned hours)
{
	if (hours < 0 || hours > 24)
	{
		std::cout << "Invalid hour";
		return;
	}
	this->hours = hours;
}

void Time::setMinutes(unsigned minutes)
{
	if (minutes < 0 || minutes > 60)
	{
		std::cout << "Invalid minutes";
		return;
	}
	this->minutes = minutes;
}

void Time::setSeconds(unsigned seconds)
{
	if (seconds < 0 || seconds > 60)
	{
		std::cout << "Invalid seconds";
		return;
	}
	this->seconds = seconds;
}

void Time::print() const
{
	std::cout << hours << ":" << minutes << ":" << seconds << std::endl;
}

void Time::nextSecond()
{
	seconds++;
	if (seconds == 60)
	{
		seconds = 0;
		nextMinute();
	}
}

void Time::nextMinute()
{
	minutes++;
	if (minutes == 60)
	{
		minutes = 0;
		nextHour();
	}
}

void Time::nextHour()
{
	hours = (hours + 1) % 24;
}

bool Time::isNight() const
{
	return hours >= 22 || hours < 6;
}
