#pragma once

class Student
{
public:
	Student();

	const char* getName() const;
	unsigned getYear() const;
	float getGrade() const;

	void setName(const char* newName);
	void setYear(int newYear);
	void setGrade(float newGrade);

	void printStudent() const;
	bool canGetScholarship(float minGrade);
	int getYearInUni(unsigned currYear);

private:
	char name[32];
	unsigned year;  //birthYear
	float grade;
};