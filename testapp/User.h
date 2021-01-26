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
	User(const char* nome, const char* cognome, const char* indirizzo, const char* dataNascita, const char* email, const char* username, const char* password);
	//destructor
	~User();

	const char* getNome();
	const char* getEmail();
	const char* getPassword();
	const char* getCognome();
	const char* getUsername();
	const char* getIndirizzo();
	const char* getDataNascita();

	// Setters
	void setNome(const char* nome);
	void setEmail(const char* email);
	void setPassword(const char* password);
	void setCognome(const char* cognome);
	void setUsername(const char* username);
	void setIndirizzo(const char* indirizzo);
	void setDataNascita(const char* dataNascita);

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
	const char* m_nome;
	const char* m_cognome;
	const char* m_indirizzo;
	const char* m_dataNascita;
	const char* m_email;
	const char* m_username;
	const char* m_password;


	


};


#endif
