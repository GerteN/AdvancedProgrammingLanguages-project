#include "pch.h"
#include "User.h"


User::User(int userId, string nome, string cognome, string indirizzo, string dataNascita, string email, string username, string password, string dataIscrizione, char gender) : m_userId(userId), m_nome(nome), m_cognome(cognome), m_indirizzo(indirizzo), m_dataNascita(dataNascita), m_email(email), m_username(username), m_password(password), m_dataIscrizione(dataIscrizione), m_gender(gender){
}
User::User(string nome, string cognome, string indirizzo, string dataNascita, string email, string username, string password, char gender) : m_nome(nome), m_cognome(cognome), m_indirizzo(indirizzo), m_dataNascita(dataNascita), m_email(email), m_username(username), m_password(password), m_gender(gender) {
	m_userId = -1;
}
User::~User() {}

bool User::operator==(const User& other) { return false; }
bool User::operator!=(const User& other) { return false; }

int User::getUserId() {
	return m_userId;
}

string User::getEmail() {
	return m_email;
}

string User::getCognome() {
	return m_cognome;
}

string User::getIndirizzo() {
	return m_indirizzo;
}

string User::getDataNascita() {
	return m_dataNascita;
}

string User::getUsername() {
	return m_username;
}

string User::getNome() {
	return m_nome;
}

string User::getPassword() {
	return m_password;
}

string getDataIscrizione() {
	return m_dataIscrizione;
}

char getGender() {
	return m_gender;
}

void User::setUserId(int userId) {
	m_userId = userId;
}
void User::setCognome(string cognome) {
	m_cognome = cognome;
}

void User::setIndirizzo(string indirizzo) {
	m_indirizzo = indirizzo;
}
void User::setDataNascita(string dataNascita) {
	m_dataNascita = dataNascita;
}

void User::setUsername(string username) {
	m_username = username;
}

void User::setEmail(string email) {
	m_email = email;
}

void User::setNome(string nome) {
	m_nome = nome;
}

void User::setPassword(string password) {
	m_password = password;
}

void setDataIscrizione(string dataIscrizione) {
	m_dataIscrizione = dataIscrizione;
}

void setGender(char gender) {
	m_gender = gender;
}








