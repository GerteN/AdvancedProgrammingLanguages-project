#pragma once
#ifndef ISTRUTTORE_H_
#define ISTRUTTORE_H_

#include <string>

using namespace std;
class Istruttore
{
public:
	Istruttore(int instructorId, string name, string surname);
	Istruttore(string name, string surname);
	~Istruttore();

	bool operator==(const Istruttore& other);
	bool operator!=(const Istruttore& other);

	int getInstructorId();
	string getName();
	string getSurname();

	void setInstructorId(int instructorId);
	void setName(string name);
	void setSurname(string surname);


private:
	int m_instructorId;
	string m_name;
	string m_surname;
};

#endif

