// dllmain.cpp : Definisce il punto di ingresso per l'applicazione DLL.
#include "pch.h"
#include <iostream>
#include "User.h"
#include "Admin.h"
#include <boost/python.hpp>
#include <mysql.h>
#include <list>
#include <boost/python/suite/indexing/vector_indexing_suite.hpp>
#include <boost/python/return_internal_reference.hpp>
#include <boost/python/module.hpp>
#include <boost/python/class.hpp>
#include "db.h"
#include <boost/python/exception_translator.hpp>
#include <exception>



boost::shared_ptr<User> validateUser(db DB, string username, string password) {
    string query = "select * from users where username = '" + username + "' and password = '" + password + "'";
    std::vector<std::string> lista = DB.queryDB(DB.getConn(), query.c_str(), true);
    if (lista.empty())
        return NULL;
    boost::shared_ptr<User> user_ptr(new User(lista[0].c_str(), lista[1].c_str(), lista[2].c_str(), lista[3].c_str(), lista[4].c_str(), lista[5].c_str(), lista[6].c_str()));
    return user_ptr;
}

boost::shared_ptr<Admin> validateAdmin(db DB, string username, string password) {
    string query = "select * from admins where username = '" + username + "' and password = '" + password + "'";
    std::vector<std::string> lista = DB.queryDB(DB.getConn(), query.c_str(), true);
    if (lista.empty())
        return NULL;
    boost::shared_ptr<Admin> admin_ptr(new Admin(lista[0].c_str(), lista[1].c_str(), lista[2].c_str(), lista[3].c_str(), lista[4].c_str(), lista[5].c_str(), lista[6].c_str(), true));
    return admin_ptr;
}

void createAdmin(Admin admin, db DB) {
    string nome(admin.getNome());
    string cognome(admin.getCognome());
    string email(admin.getEmail());
    string indirizzo(admin.getIndirizzo());
    string dataNascita(admin.getDataNascita());
    string password(admin.getPassword());
    string username(admin.getUsername());
    string query = "INSERT INTO admins (nome, cognome, indirizzo, dataNascita, email, username, pass) VALUES(" + nome + cognome + indirizzo + dataNascita + email + username + password + ")";
    if (mysql_query(DB.getConn(), query.c_str()))
    {
        std::string error = "unable to insert user with username: " + username + ", name:  " + nome + ", cognome: " + cognome + " into user table";
        throw std::runtime_error(error);
        mysql_close(DB.getConn());
        exit(1);
    }
}



void createUser(User user, db DB) {
    string nome(user.getNome());
    string cognome(user.getCognome());
    string email(user.getEmail());
    string indirizzo(user.getIndirizzo());
    string dataNascita(user.getDataNascita());
    string password(user.getPassword());
    string username(user.getUsername());
    string query = "INSERT INTO users (nome, cognome, indirizzo, dataNascita, email, username, pass) VALUES('"+ nome + "', '" + cognome + "', '" + indirizzo + "', '" + dataNascita + "', '" + email + "', '" + username + "', '" + password +"')";
    if (mysql_query(DB.getConn(), query.c_str()))
    {
        std::string error = "unable to insert user with username: "+ username + ", name:  "+ nome + ", cognome: "+cognome + " into user table";
        throw std::runtime_error(error);
        mysql_close(DB.getConn());
        exit(1);
    }
}


BOOST_PYTHON_MODULE(testapp) {
    using namespace boost::python;
    class_<lista>("lista").def(vector_indexing_suite<lista>());
    class_<MYSQL>("MYSQL");
    class_<User, boost::shared_ptr<User>, boost::noncopyable>("User", no_init);
    class_<Admin, boost::shared_ptr<Admin>, boost::noncopyable>("Admin", no_init);
    
    def("validateUser", validateUser);
    def("validateAdmin", validateAdmin);
    def("createUser", createUser);
    def("createAdmin", createAdmin);

    class_<Admin, boost::noncopyable, boost::shared_ptr<Admin>>("Admin")
        .def(init<const char*, const char*, const char*, const char*, const char*, const char*, const char*, bool>())
        .def("getNome", &Admin::getNome)
        .def("getCognome", &Admin::getCognome)
        .def("getEmail", &Admin::getEmail)
        .def("getIndirizzo", &Admin::getIndirizzo)
        .def("getUsername", &Admin::getUsername)
        .def("getPassword", &Admin::getPassword)
        .def("getDataDiNascita", &Admin::getDataNascita)
        .def("isAdmin", &Admin::getIsAdmin);

    class_<db, boost::noncopyable>("db")
        .def(init<>())
        .def("close", &db::close)
        .def<void (db::*)(MYSQL*, const char*, const char*, const char*, int)>("connectHost", &db::connect)
        .def<void (db::*)(MYSQL*, const char*, const char*, const char*, int, std::string)>("connectDB", &db::connect)
        .def("createDB", &db::createDB)
        .def<void (db::*)(MYSQL*, const char*)>("insertDB", &db::queryDB)
        .def<lista(db::*)(MYSQL*, const char*, bool)>("queryDB", &db::queryDB)
        .def("getConn", &db::getConn, return_internal_reference<>())
        .def("getResult", &db::getResult, return_internal_reference<>())
        .def("setRow", &db::setRow)
        .def("setResult", &db::setResult);

    class_<User, boost::noncopyable, boost::shared_ptr<User>>("User")
        .def(init<const char*, const char*, const char*, const char*, const char*, const char*, const char*>())
        .def("getNome", &User::getNome)
        .def("getCognome", &User::getCognome)
        .def("getEmail", &User::getEmail)
        .def("getIndirizzo", &User::getIndirizzo)
        .def("getUsername", &User::getUsername)
        .def("getPassword", &User::getPassword)
        .def("getDataDiNascita", &User::getDataNascita);

    
}


