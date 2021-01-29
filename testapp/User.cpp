#include "pch.h"
#include "User.h"

User::User(){}
User::User(const char* nome, const char* cognome, const char* indirizzo, const char* dataNascita, const char* email, const char* username, const char* password) : m_nome(nome), m_cognome(cognome), m_indirizzo(indirizzo), m_dataNascita(dataNascita), m_email(email), m_username(username), m_password(password){
}

User::~User() {}

const char* User::getEmail() {
	return m_email;
}

const char* User::getCognome() {
	return m_cognome;
}

const char* User::getIndirizzo() {
	return m_indirizzo;
}

const char* User::getDataNascita() {
	return m_dataNascita;
}

const char* User::getUsername() {
	return m_username;
}

const char* User::getNome() {
	return m_nome;
}

const char* User::getPassword() {
	return m_password;
}

void User::setCognome(const char* cognome) {
	m_cognome = cognome;
}

void User::setIndirizzo(const char* indirizzo) {
	m_indirizzo = indirizzo;
}
void User::setDataNascita(const char* dataNascita) {
	m_dataNascita = dataNascita;
}

void User::setUsername(const char* username) {
	m_username = username;
}

void User::setEmail(const char* email) {
	m_email = email;
}

void User::setNome(const char* nome) {
	m_nome = nome;
}

void User::setPassword(const char* password) {
	m_password = password;
}








