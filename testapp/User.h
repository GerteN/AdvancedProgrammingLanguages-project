#pragma once

#ifndef USER_H_
#define USER_H_

#include <string>
#include <boost/python.hpp>
using namespace std;
class User {

public:
	//constructor
	User(string nome, string cognome, string indirizzo, string dataNascita, string email, string username, string password, char gender);
	User(int userId, string nome, string cognome, string indirizzo, string dataNascita, string email, string username, string password, string dataIscrizione, char gender);
	//destructor
	~User();

	bool operator==(const User& other);
	bool operator!=(const User& other);

	int getUserId();
	string getNome();
	string getEmail();
	string getPassword();
	string getCognome();
	string getUsername();
	string getIndirizzo();
	string getDataNascita();
	string getDataIscrizione();
	char getGender();

	// Setters
	void setUserId(int userId);
	void setNome(string nome);
	void setEmail(string email);
	void setPassword(string password);
	void setCognome(string cognome);
	void setUsername(string username);
	void setIndirizzo(string indirizzo);
	void setDataNascita(string dataNascita);
	void setDataIscrizione(string dataIscrizione);
	void setGender(char gender);

	



protected:
	int m_userId;
	string m_nome;
	string m_cognome;
	string m_indirizzo;
	string m_dataNascita;
	string m_email;
	string m_username;
	string m_password;
	string m_dataIscrizione;
	char m_gender;


	


};


#endif
