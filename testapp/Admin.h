#pragma once
#ifndef ADMIN_H_
#define ADMIN_H_
#include "User.h"

class Admin : public User {
public:
	Admin();
	Admin(string nome, string cognome, string indirizzo, string dataNascita, string email, string username, string password, bool isAdmin);
	~Admin();

	void setIsAdmin(bool isAdmin);
	bool getIsAdmin();

private:
	bool m_isAdmin;
};

#endif

