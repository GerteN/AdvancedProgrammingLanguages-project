#include "pch.h"
//#include "User.h"

#include "Admin.h"

Admin::Admin(string nome, string cognome, string indirizzo, string dataNascita, string email, string username, string password, bool isAdmin) : User(nome, cognome, indirizzo, dataNascita, email, username, password), m_isAdmin(isAdmin) {
	m_userId = -1;
}
Admin::Admin(int userId, string nome, string cognome, string indirizzo, string dataNascita, string email, string username, string password, bool isAdmin) : User(userId, nome, cognome, indirizzo, dataNascita, email, username, password), m_isAdmin(isAdmin) {}
Admin::~Admin() {}

bool Admin::operator==(const Admin& other) { return false; }
bool Admin::operator!=(const Admin& other) { return false; }

void Admin::setIsAdmin(bool isAdmin) {
	m_isAdmin = isAdmin;
}

bool Admin::getIsAdmin() {
	return m_isAdmin;
}