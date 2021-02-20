#pragma once

#ifndef USER_H_
#define USER_H_

#include <string>
#include <boost/python.hpp>
using namespace std;
class User {

public:
	//constructor
	User();
	User(string nome, string cognome, string indirizzo, string dataNascita, string email, string username, string password);
	//destructor
	~User();

	string getNome();
	string getEmail();
	string getPassword();
	string getCognome();
	string getUsername();
	string getIndirizzo();
	string getDataNascita();

	// Setters
	void setNome(string nome);
	void setEmail(string email);
	void setPassword(string password);
	void setCognome(string cognome);
	void setUsername(string username);
	void setIndirizzo(string indirizzo);
	void setDataNascita(string dataNascita);

	//virtual function

	/*User(const User&) = delete;
	User& operator=(const User&) = delete;*/

	/*template <typename T>
	boost::python::object transfer_to_python(T* t)
	{
		// Transfer ownership to a smart pointer, allowing for proper cleanup
		// incase Boost.Python throws.
		std::unique_ptr<T> ptr(t);

		// Use the manage_new_object generator to transfer ownership to Python.
		namespace python = boost::python;
		typename python::manage_new_object::apply<T*>::type converter;

		// Transfer ownership to the Python handler and release ownership
		// from C++.
		python::handle<> handle(converter(*ptr));
		ptr.release();

		return python::object(handle);
	}*/



protected:
	string m_nome;
	string m_cognome;
	string m_indirizzo;
	string m_dataNascita;
	string m_email;
	string m_username;
	string m_password;


	


};


#endif
