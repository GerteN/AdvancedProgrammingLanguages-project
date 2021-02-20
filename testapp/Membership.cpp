#include "pch.h"
#include "Membership.h"

Membership::Membership(string courseName, int courseId) : m_courseName(courseName), m_courseId(courseId){}
Membership::~Membership() {}

string Membership::getCourseName() {
	return m_courseName;
}

int Membership::getCourseId() {
	return m_courseId;
}

void Membership::setCourseName(string courseName) {
	m_courseName = courseName;
}
void Membership::setCourseId(int courseId) {
	m_courseId = courseId;
}
