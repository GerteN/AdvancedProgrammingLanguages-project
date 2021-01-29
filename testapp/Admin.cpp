#include "pch.h"
//#include "User.h"

#include "Admin.h"

Admin::Admin(){}
Admin::Admin(const char* nome, const char* cognome, const char* indirizzo, const char* dataNascita, const char* email, const char* username, const char* password, bool isAdmin) : User(nome, cognome, indirizzo, dataNascita, email, username, password), m_isAdmin(isAdmin) {}
Admin::~Admin() {}

void Admin::setIsAdmin(bool isAdmin) {
	m_isAdmin = isAdmin;
}

bool Admin::getIsAdmin() {
	return m_isAdmin;
}