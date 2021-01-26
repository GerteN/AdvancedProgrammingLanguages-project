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



bool validate(string password, const char* formPassword) {
    if (password.compare(formPassword) == 0)
        return true;
    return false;

}

PyObject* except = 0;
using namespace boost::python;
BOOST_PYTHON_MODULE(testapp) {
    class_<lista>("lista").def(vector_indexing_suite<lista>());
    class_<MYSQL>("MYSQL");
    
    def("validate", validate);
    class_<Admin, boost::noncopyable, boost::shared_ptr<Admin>>("Admin")
        .def(init<const char*, const char*, const char*, const char*, const char*, const char*, const char*, bool>())
        .def("getNome", &Admin::getNome)
        .def("getCognome", &Admin::getCognome)
        .def("getEmail", &Admin::getEmail)
        .def("getIndirizzo", &Admin::getIndirizzo)
        .def("getUsername", &Admin::getUsername)
        .def("getPassword", &Admin::getPassword)
        .def("getDataDiNascita", &Admin::getDataNascita);

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


