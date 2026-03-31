#include "Student.h"

#include <iostream>
#include <cstring>

Student::Student()
{
	strncpy_s(name, "Unknown", 8);
	year = 2000;
	grade = 2.0;
}

const char* Student::getName() const
{
	return this->name;
}

unsigned Student::getYear() const
{
	return this->year;
}

float Student::getGrade() const
{
	return this->grade;
}

void Student::setName(const char* newName)
{
	if (!newName || strlen(newName) == 0)
	{
		std::cout << "Invalid name";
		return;
	}

	strncpy_s(name, newName, 31);
	name[31] = '\0';
}

void Student::setYear(int newYear)
{
	if (newYear < 1960)
	{
		std::cout << "Invalid year";
		return;
	}
	year = newYear;
}

void Student::setGrade(float newGrade)
{
	if (newGrade < 2.0f || newGrade > 6.0f)
	{
		std::cout << "Invalid grade";
		return;
	}
	grade = newGrade;
}

void Student::printStudent() const
{
	std::cout << "Name: " << name << '\n'
		<< "Birth year: " << year << '\n'
		<< "Grade: " << grade << '\n';
}

bool Student::canGetScholarship(float minGrade)
{
	return grade >= minGrade;
}

int Student::getYearInUni(unsigned currYear)
{
	int age = currYear - year;
	return age - 19;
}
