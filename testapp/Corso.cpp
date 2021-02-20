#include "pch.h"
#include "Corso.h"

Corso::Corso(string courseName, int days, double monthlyCost, int instructorId) : m_courseName(courseName), m_days(days), m_monthlyCost(monthlyCost), m_instructorId(instructorId){}
Corso::~Corso() {}

string Corso::getCourseName() {
	return m_courseName;
}
int Corso::getDays() {
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
void Corso::setDays(int days) {
	m_days = days;
}
void Corso::setMonthlyCost(double monthlyCost) {
	m_monthlyCost = monthlyCost;
}
void Corso::setInstructorId(int instructorId) {
	m_instructorId = instructorId;
}