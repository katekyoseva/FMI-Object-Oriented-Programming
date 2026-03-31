#pragma once

class Date {
public:
	Date();

	unsigned getDay() const;
	unsigned getMonth() const;
	unsigned getYear() const;

	void setDay(int day);
	void setMonth(unsigned month);
	void setYear(unsigned year);

	void print() const;

	void nextDay();
	void nextMonth();
	void nextYear();

	bool isDuringSummer();

private:
	bool isLeap() const;
	unsigned daysInMonth() const;
	unsigned day;
	unsigned month;
	unsigned year;
};