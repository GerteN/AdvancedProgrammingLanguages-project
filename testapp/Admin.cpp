#include "pch.h"
//#include "User.h"

#include "Admin.h"

Admin::Admin(std::string nome, std::string cognome, std::string indirizzo, std::string dataNascita, std::string email, std::string username, std::string password, char gender, bool isAdmin) : User(nome, cognome, indirizzo, dataNascita, email, username, password, gender), m_isAdmin(isAdmin) {
	m_userId = -1;
}
Admin::Admin(int userId, std::string nome, std::string cognome, std::string indirizzo, std::string dataNascita, std::string email, std::string username, std::string password, std::string dataIscrizione, char gender, bool isAdmin) : User(userId, nome, cognome, indirizzo, dataNascita, email, username, password, dataIscrizione, gender), m_isAdmin(isAdmin) {}
Admin::~Admin() {}

bool Admin::operator==(const Admin& other) { return false; }
bool Admin::operator!=(const Admin& other) { return false; }

void Admin::setIsAdmin(bool isAdmin) {
	m_isAdmin = isAdmin;
}

bool Admin::getIsAdmin() const {
	return m_isAdmin;
}