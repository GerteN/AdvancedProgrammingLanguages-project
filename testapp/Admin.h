#pragma once
#ifndef ADMIN_H_
#define ADMIN_H_
#include "User.h"

class Admin : public User {
public:
	Admin();
	Admin(const char* nome, const char* cognome, const char* indirizzo, const char* dataNascita, const char* email, const char* username, const char* password, bool isAdmin);
	~Admin();

	void setIsAdmin(bool isAdmin);
	bool getIsAdmin();

private:
	bool m_isAdmin;
};

#endif

