#include "pch.h"
#include "Corso.h"

Corso::Corso(string courseName, string days, double monthlyCost, int instructorId) : m_courseName(courseName), m_days(days), m_monthlyCost(monthlyCost), m_instructorId(instructorId){}
Corso::~Corso() {}

bool Corso::operator==(const Corso& other) { return false; }
bool Corso::operator!=(const Corso& other) { return false; }

string Corso::getCourseName() {
	return m_courseName;
}
string Corso::getDays() {
	return m_days;
}
double Corso::getMonthlyCost(){
	return m_monthlyCost;
}
int Corso::getInstructorId(){
	return m_instructorId;
}

void Corso::setCourseName(string courseName) {
	m_courseName = courseName;
}
void Corso::setDays(string days) {
	m_days = days;
}
void Corso::setMonthlyCost(double monthlyCost) {
	m_monthlyCost = monthlyCost;
}
void Corso::setInstructorId(int instructorId) {
	m_instructorId = instructorId;
}