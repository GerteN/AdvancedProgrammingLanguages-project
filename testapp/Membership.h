#pragma once
#ifndef MEMBERSHIP_H_
#define MEMBERSHIP_H_
#include <string>

using namespace std;
class Membership
{
public:
	Membership(string courseName, int userId);
	~Membership();

	bool operator==(const Membership& other);
	bool operator!=(const Membership& other);

	string getCourseName();
	int getUserId();
	
	void setCourseName(string courseName);
	void setUserId(int userId);
private:
	string m_courseName;
	int m_userId;
};

#endif


