#include "pch.h"
#include "Istruttore.h"

Istruttore::Istruttore(int instructorId, string name, string surname) : m_instructorId(instructorId), m_name(name), m_surname(surname){}
Istruttore::Istruttore(string name, string surname) : m_name(name), m_surname(surname) {}
Istruttore::~Istruttore(){}

int Istruttore::getInstructorId() {
	return m_instructorId;
}
string Istruttore::getName() {
	return m_name;
}
string Istruttore::getSurname() {
	return m_surname;
}

void Istruttore::setInstructorId(int instructorId) {
	m_instructorId = instructorId;
}
void Istruttore::setName(string name) {
	m_name = name;
}
void Istruttore::setSurname(string surname) {
	m_surname = surname;
}
