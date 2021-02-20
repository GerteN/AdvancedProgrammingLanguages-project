#pragma once

#ifndef CORSO_H_
#define CORSO_H_

#include <string>
using namespace std;
class Corso
{
public:
	Corso(string courseName, int days, double monthlyCost, int instructorId);
	~Corso();
	
	string getCourseName();
	int getDays();
	double getMonthlyCost();
	int getInstructorId();

	void setCourseName(string courseName);
	void setDays(int days);
	void setMonthlyCost(double monthlyCost);
	void setInstructorId(int instructorId);

private:

	string m_courseName;
	int m_days;
	double m_monthlyCost;
	int m_instructorId;

};

#endif

