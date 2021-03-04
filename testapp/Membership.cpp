#include "pch.h"
#include "Membership.h"

Membership::Membership(string courseName, int userId) : m_courseName(courseName), m_userId(userId){}
Membership::~Membership() {}

bool Membership::operator==(const Membership& other) { return false; }
bool Membership::operator!=(const Membership& other) { return false; }

string Membership::getCourseName() {
	return m_courseName;
}

int Membership::getUserId() {
	return m_userId;
}

void Membership::setCourseName(string courseName) {
	m_courseName = courseName;
}
void Membership::setUserId(int userId) {
	m_userId = userId;
}
