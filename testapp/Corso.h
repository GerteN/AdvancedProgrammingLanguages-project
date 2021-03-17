#pragma once

#ifndef CORSO_H_
#define CORSO_H_

#include <string>
using namespace std;
class Corso
{
public:
	Corso(string courseName, string days, double monthlyCost, int instructorId);
	~Corso();
	
	bool operator==(const Corso& other);
	bool operator!=(const Corso& other);

	string getCourseName() const;
	string getDays() const;
	double getMonthlyCost() const;
	int getInstructorId() const;

	void setCourseName(string courseName);
	void setDays(string days);
	void setMonthlyCost(double monthlyCost);
	void setInstructorId(int instructorId);

private:

	string m_courseName;
	string m_days;
	double m_monthlyCost;
	int m_instructorId;

};

#endif

