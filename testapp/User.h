#pragma once

#ifndef USER_H_
#define USER_H_

#include <string>
#include <boost/python.hpp>


class User {

public:
	//constructor
	User(std::string nome, std::string cognome, std::string indirizzo, std::string dataNascita, std::string email, std::string username, std::string password, char gender);
	User(int userId, std::string nome, std::string cognome, std::string indirizzo, std::string dataNascita, std::string email, std::string username, std::string password, std::string dataIscrizione, char gender);
	//destructor
	~User();

	bool operator==(const User& other);
	bool operator!=(const User& other);

	int getUserId() const;
	std::string getNome() const;
	std::string getEmail() const;
	std::string getPassword() const;
	std::string getCognome() const;
	std::string getUsername() const;
	std::string getIndirizzo() const;
	std::string getDataNascita() const;
	std::string getDataIscrizione() const;
	char getGender() const;

	// Setters
	void setUserId(int userId);
	void setNome(std::string nome);
	void setEmail(std::string email);
	void setPassword(std::string password);
	void setCognome(std::string cognome);
	void setUsername(std::string username);
	void setIndirizzo(std::string indirizzo);
	void setDataNascita(std::string dataNascita);
	void setDataIscrizione(std::string dataIscrizione);
	void setGender(char gender);

	



protected:
	int m_userId;
	std::string m_nome;
	std::string m_cognome;
	std::string m_indirizzo;
	std::string m_dataNascita;
	std::string m_email;
	std::string m_username;
	std::string m_password;
	std::string m_dataIscrizione;
	char m_gender;


	


};


#endif
