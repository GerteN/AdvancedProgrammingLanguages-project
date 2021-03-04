#pragma once
#ifndef ADMIN_H_
#define ADMIN_H_
#include "User.h"

class Admin : public User {
public:
	Admin(string nome, string cognome, string indirizzo, string dataNascita, string email, string username, string password, bool isAdmin);
	Admin(int userId, string nome, string cognome, string indirizzo, string dataNascita, string email, string username, string password, bool isAdmin);
	~Admin();

	bool operator==(const Admin& other);
	bool operator!=(const Admin& other);
	
	void setIsAdmin(bool isAdmin);
	bool getIsAdmin();

private:
	bool m_isAdmin;
};

#endif

