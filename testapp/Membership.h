#pragma once
#ifndef MEMBERSHIP_H_
#define MEMBERSHIP_H_
#include <string>

using namespace std;
class Membership
{
public:
	Membership(string courseName, int courseId);
	~Membership();

	string getCourseName();
	int getCourseId();
	
	void setCourseName(string courseName);
	void setCourseId(int courseId);
private:
	string m_courseName;
	int m_courseId;
};

#endif


