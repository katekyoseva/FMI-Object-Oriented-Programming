#include "Date.h"
#include <iostream>

Date::Date()
{
	day = 1;
	month = 1;
	year = 1970;
}

unsigned Date::getDay() const
{
	return day;
}

unsigned Date::getMonth() const
{
	return month;
}

unsigned Date::getYear() const
{
	return year;
}

void Date::setDay(int day)
{
	if (day < 1 || day > 31)
	{
		std::cout << "Invalid date!";
		return;
	}

	this->day = day;
}

void Date::setMonth(unsigned month)
{
	if (month < 1 || month > 12)
	{
		std::cout << "Invalid month!";
		return;
	}

	this->month = month;
}

void Date::setYear(unsigned year)
{
	if (year < 1970)
	{
		std::cout << "Invalid year!";
		return;
	}

	this->year = year;
}

bool Date::isLeap() const
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

unsigned Date::daysInMonth() const
{
	switch (month)
	{
		case 2: 
			return isLeap() ? 29 : 28;
		case 4: 
		case 6: 
		case 9: 
		case 11:
			return 30;
		default: 
			return 31;
	}
}

void Date::print() const
{
	std::cout << day << '.' << month << '.' << year << '\n';
}

void Date::nextDay()
{
	day++;
	if (day > daysInMonth())
	{
		day = 1;
		month++;
		if (month > 12)
		{
			month = 1;
			year++;
		}
	}
}

void Date::nextMonth()
{
	month++;
	if (month > 12)
	{
		month = 1;
		year++;
	}
}

void Date::nextYear()
{
	year++;
}

bool Date::isDuringSummer()
{
	return month >= 7 && month <= 8;
}
