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

void prepareStrings(string& str, char sep, vector<string>& out)
{
    size_t start;
    size_t end = 0;

    while ((start = str.find_first_not_of(sep, end)) != string::npos)
    {
        end = str.find(sep, start);
        out.push_back(str.substr(start, end - start));
    }
}

bool checkPassword(string passwordDB, string passwordToCheck) {

    int pass = stoi(passwordDB);
    size_t passDB = (pass);
    hash<string> stringHash;
    if (stringHash(passwordToCheck) == passDB)
        return true;
    return false;
}


User* validateUser(db DB, string username, string password) {
    string query = "select * from users where username = '" + username + "' and password = '" + password + "'";
    std::vector<std::string> lista = DB.queryDB(DB.getConn(), query.c_str(), true);
    if (lista.empty())
        return nullptr;

    string tmp = lista[0];
    char sep = ' ';
    vector<string> out;
    prepareStrings(tmp, sep, out);
    /*if (!checkPassword(out[6], password))
        return nullptr;*/

    User *user = new User(out[0], out[1], out[2], out[3], out[4], out[5], out[6]);
    return user;
}

Admin* validateAdmin(db DB, string username, string password) {
    string query = "select * from admins where username = '" + username + "' and password = '" + password + "'";
    std::vector<std::string> lista = DB.queryDB(DB.getConn(), query.c_str(), true);
    if (lista.empty())
        return nullptr;
    string tmp = lista[0];
    char sep = ' ';
    vector<string> out;
    prepareStrings(tmp, sep, out);

    
    /*if (!checkPassword(out[6], password))
        return nullptr;*/

    Admin* admin = new Admin(out[0], out[1], out[2], out[3], out[4], out[5], out[6], true);
    return admin;
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
    DB.queryDB(DB.getConn(), query.c_str(), true);
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
    DB.queryDB(DB.getConn(), query.c_str(), true);
}


BOOST_PYTHON_MODULE(testapp) {
    using namespace boost::python;
    class_<lista>("lista").def(vector_indexing_suite<lista>());
    class_<MYSQL>("MYSQL");
    
    def("validateUser", validateUser, return_internal_reference<>());
    def("validateAdmin", validateAdmin, return_internal_reference<>());
    def("createUser", createUser);
    def("createAdmin", createAdmin);

    class_<Admin, boost::noncopyable>("Admin", init<string, string, string, string, string, string, string, bool>())
        .def(init<>())
        .add_property("nome", &Admin::getNome, &Admin::setNome)
        .add_property("cognome", &Admin::getCognome, &Admin::setCognome)
        .add_property("email", &Admin::getEmail, &Admin::setEmail)
        .add_property("indirizzo", &Admin::getIndirizzo, &Admin::setIndirizzo)
        .add_property("username", &Admin::getUsername, &Admin::setUsername)
        .add_property("password", &Admin::getPassword, &Admin::setPassword)
        .add_property("dataDiNascita", &Admin::getDataNascita, &Admin::setDataNascita)
        .add_property("isAdmin", &Admin::getIsAdmin, &Admin::setIsAdmin);

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

    class_<User, boost::noncopyable>("User", init<string, string, string, string, string, string, string>())
        .def(init<>())
        .add_property("nome", &User::getNome, &User::setNome)
        .add_property("cognome", &User::getCognome, &User::setCognome)
        .add_property("email", &User::getEmail, &User::setEmail)
        .add_property("indirizzo", &User::getIndirizzo, &User::setIndirizzo)
        .add_property("username", &User::getUsername, &User::setUsername)
        .add_property("password", &User::getPassword, &User::setPassword)
        .add_property("dataDiNascita", &User::getDataNascita, &User::setDataNascita);

    
}


