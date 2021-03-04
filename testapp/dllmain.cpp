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
#include "Istruttore.h"
#include "Membership.h"
#include "Corso.h"





User* validateUser(db DB, string username, string password) {
    string query = "select * from users where username = '" + username + "' and password = '" + password + "'";
    vector<lista> listUser = DB.queryDB(DB.getConn(), query.c_str(), true);
    if (listUser.empty())
        return nullptr;

    lista list = listUser[0];
    User *user = new User(stoi(list[0]), list[1], list[2], list[3], list[4], list[5], list[6], list[7], list[8], list[9][0]);
    return user;
}

Admin* validateAdmin(db DB, string username, string password) {
    string query = "select * from users where username = '" + username + "' and password = '" + password + "'";
    vector<lista> listAdmin = DB.queryDB(DB.getConn(), query.c_str(), true);
    if (listAdmin.empty())
        return nullptr;
    
    lista list = listAdmin[0];

    query = "select * from admins where admin_id = " + list[0];
    vector<lista> admin_id = DB.queryDB(DB.getConn(), query.c_str(), true);
    if (admin_id.empty())
        return nullptr;

    Admin* admin = new Admin(stoi(list[0]), list[1], list[2], list[3], list[4], list[5], list[6], list[7], list[8], list[9][0], true);
    return admin;
}

std::vector<User> getAllUsers(db DB) {
    string query = "select * from users";
    std::vector<lista> list = DB.queryDB(DB.getConn(), query.c_str(), true);
    std::vector<User> userList;
    for (auto it = list.begin(); it != list.end(); ++it) {
        User* user = new User(stoi((*it)[0]), (*it)[1], (*it)[2], (*it)[3], (*it)[4], (*it)[5], (*it)[6], (*it)[7], (*it)[8], (*it)[9][0]);
        userList.push_back(*user);
    }
    return userList;
}

void createAdmin(Admin admin, db DB) {
    string nome(admin.getNome());
    string cognome(admin.getCognome());
    string email(admin.getEmail());
    string indirizzo(admin.getIndirizzo());
    string dataNascita(admin.getDataNascita());
    string password(admin.getPassword());
    string username(admin.getUsername());
    string query = "INSERT INTO users (name, surname, address, birth_date, email, username, password) VALUES('" + nome + "', '" +
        cognome + "', '" + indirizzo + "', '" + dataNascita + "', '" + email + "', '" + username + "', '" + password + "')";
    DB.queryDB(DB.getConn(), query.c_str());
    query = "INSERT INTO admins (admin_id)  SELECT MAX(user_id) FROM users";
    DB.queryDB(DB.getConn(), query.c_str());
}


void createUser(User user, db DB) {
    string query = "SELECT * FROM users";
    lista list = DB.queryDB(DB.getConn(), query.c_str(), true).back();

    string nome(user.getNome());
    string cognome(user.getCognome());
    string email(user.getEmail());
    string indirizzo(user.getIndirizzo());
    string dataNascita(user.getDataNascita());
    string password(user.getPassword());
    string username(user.getUsername());
    query = "INSERT INTO users (name, surname, address, birth_date, email, username, password) VALUES('" + nome + "', '" +
        cognome + "', '" + indirizzo + "', '" + dataNascita + "', '" + email + "', '" + username + "', '" + password +"')";
    DB.queryDB(DB.getConn(), query.c_str());
}

void removeUser(int userId, db DB) {

    string query = "DELETE FROM users WHERE user_id = " + to_string(userId);
    DB.queryDB(DB.getConn(), query.c_str());

}

void modifyUser(int userId, string email, string username, string password, db DB) {
    string query = "UPDATE users SET email = '" + email + "',username = '" + username + "', password = '" + password + "' WHERE user_id = " + to_string(userId) + "";
    DB.queryDB(DB.getConn(), query.c_str());

}

void createInstructor(Istruttore istruttore, db DB) {
    string name = istruttore.getName();
    string surname = istruttore.getSurname();
    string query = "INSERT INTO instructors(name, surname) VALUES('" + name + "', '" + surname + "')";
    DB.queryDB(DB.getConn(), query.c_str());
}

void removeInstructor(int instructorId, db DB) {
    string instructorID = to_string(instructorId);
    string query = "DELETE FROM instructors WHERE instructor_id = " + instructorID + "";
    DB.queryDB(DB.getConn(), query.c_str());

}

std::vector<Istruttore> getAllInstructors(db DB) {
    string query = "select * from instructors";
    std::vector<lista> list = DB.queryDB(DB.getConn(), query.c_str(), true);
    std::vector<Istruttore> instructorList;
    for (auto it = list.begin(); it != list.end(); ++it) {
        Istruttore* istruttore = new Istruttore(stoi((*it)[0]), (*it)[1], (*it)[2]);
        instructorList.push_back(*istruttore);
    }
    return instructorList;
}

void removeCourse(string courseName, db DB) {
    string query = "DELETE FROM courses WHERE course_name = '" + courseName + "'";
    DB.queryDB(DB.getConn(), query.c_str());
}

void createCourse(Corso corso, db DB) {
    string courseName = corso.getCourseName();
    string days = corso.getDays();
    string monthlyCost = to_string(corso.getMonthlyCost());
    string instructorId = to_string(corso.getInstructorId());
    string query = "INSERT INTO courses(course_name, days, monthly_cost, instructor_id) VALUES('" + courseName + "', '" + days + "', " + monthlyCost + ", " + instructorId + ")";
    DB.queryDB(DB.getConn(), query.c_str());
}

std::vector<Corso> getAllCourses(db DB) {
    string query = "select * from courses";
    std::vector<lista> list = DB.queryDB(DB.getConn(), query.c_str(), true);
    std::vector<Corso> courseList;
    for (auto it = list.begin(); it != list.end(); ++it) {
        Corso* corso = new Corso((*it)[0], (*it)[1], stod((*it)[2]), stoi((*it)[3]));
        courseList.push_back(*corso);
    }
    return courseList;
}

void createMembership(Membership membership, db DB) {
    string courseName = membership.getCourseName();
    string userId = to_string(membership.getUserId());
    string query = "INSERT INTO membership(user_id, course_name) VALUES('" + userId + "', '" +  courseName + "')";
    DB.queryDB(DB.getConn(), query.c_str());
}

void removeMembership(int userId, string courseName, db DB) {
    string query = "DELETE FROM membership WHERE course_name = '" + courseName + "'and user_id='" + (to_string(userId)) + "'";
    DB.queryDB(DB.getConn(), query.c_str());
}

std::vector<Membership> getAllMemberships(db DB) {
    string query = "select * from membership";
    std::vector<lista> list = DB.queryDB(DB.getConn(), query.c_str(), true);
    std::vector<Membership> membershipList;
    for (auto it = list.begin(); it != list.end(); ++it) {
        Membership* membership = new Membership(((*it)[0]), stoi((*it)[1]));
        membershipList.push_back(*membership);
    }
    return membershipList;

}



using namespace boost::python;
BOOST_PYTHON_MODULE(testapp) {
    
    class_<lista>("lista").def(vector_indexing_suite<lista>());
    class_<vector<User>>("userList").def(vector_indexing_suite<vector<User>>());
    class_<vector<Corso>>("courseList").def(vector_indexing_suite<vector<Corso>>());
    class_<vector<Istruttore>>("instructorList").def(vector_indexing_suite<vector<Istruttore>>());
    class_<vector<Membership>>("membershipList").def(vector_indexing_suite<vector<Membership>>());
    class_<MYSQL>("MYSQL");
    
    def("validateUser", validateUser, return_internal_reference<>());
    def("validateAdmin", validateAdmin, return_internal_reference<>());
    def("createUser", createUser);
    def("createAdmin", createAdmin);
    def("createInstructor", createInstructor);
    def("createCourse", createCourse);
    def("createMembership", createMembership);
    def("removeUser", removeUser);
    def("removeInstructor", removeInstructor);
    def("removeCourse", removeCourse);
    def("removeMembership", removeMembership);
    def("modifyUser", modifyUser);
    def("getAllUsers", getAllUsers);
    def("getAllInstructors", getAllInstructors);
    def("getAllCourses", getAllCourses);
    def("getAllMemberships", getAllMemberships);

    class_<Admin, boost::noncopyable>("Admin", init<string, string, string, string, string, string, string, char, bool>())
        .add_property("userId", &Admin::getUserId, &Admin::setUserId)
        .add_property("nome", &Admin::getNome, &Admin::setNome)
        .add_property("cognome", &Admin::getCognome, &Admin::setCognome)
        .add_property("email", &Admin::getEmail, &Admin::setEmail)
        .add_property("indirizzo", &Admin::getIndirizzo, &Admin::setIndirizzo)
        .add_property("username", &Admin::getUsername, &Admin::setUsername)
        .add_property("password", &Admin::getPassword, &Admin::setPassword)
        .add_property("dataDiNascita", &Admin::getDataNascita, &Admin::setDataNascita)
        .add_property("isAdmin", &Admin::getIsAdmin, &Admin::setIsAdmin)
        .add_property("dataIscrizione", &Admin::getDataIscrizione, &Admin::setDataIscrizione)
        .add_property("gender", &Admin::getGender, &Admin::setGender);

    class_<db, boost::noncopyable>("db")
        .def(init<>())
        .def("close", &db::close)
        .def<void (db::*)(MYSQL*, const char*, const char*, const char*, int)>("connectHost", &db::connect)
        .def<void (db::*)(MYSQL*, const char*, const char*, const char*, int, std::string)>("connectDB", &db::connect)
        .def("createDB", &db::createDB)
        .def<void (db::*)(MYSQL*, const char*)>("insertDB", &db::queryDB)
        .def<std::vector<lista>(db::*)(MYSQL*, const char*, bool)>("queryDB", &db::queryDB)
        .def("getConn", &db::getConn, return_internal_reference<>())
        .def("getResult", &db::getResult, return_internal_reference<>())
        .def("setRow", &db::setRow)
        .def("setResult", &db::setResult);

    class_<User, boost::noncopyable>("User", init<string, string, string, string, string, string, string, char>())
        .add_property("userId", &User::getUserId, &User::setUserId)
        .add_property("nome", &User::getNome, &User::setNome)
        .add_property("cognome", &User::getCognome, &User::setCognome)
        .add_property("email", &User::getEmail, &User::setEmail)
        .add_property("indirizzo", &User::getIndirizzo, &User::setIndirizzo)
        .add_property("username", &User::getUsername, &User::setUsername)
        .add_property("password", &User::getPassword, &User::setPassword)
        .add_property("dataDiNascita", &User::getDataNascita, &User::setDataNascita)
        .add_property("dataIscrizione", &User::getDataIscrizione, &User::setDataIscrizione)
        .add_property("gender", &User::getGender, &User::setGender);

    class_<Istruttore, boost::noncopyable>("Istruttore", init<string, string>())
        .add_property("instructorId", &Istruttore::getInstructorId, &Istruttore::setInstructorId)
        .add_property("name", &Istruttore::getName, &Istruttore::setName)
        .add_property("surname", &Istruttore::getSurname, &Istruttore::setSurname);
    
    class_<Corso, boost::noncopyable>("Corso", init<string, string, double, int>())
        .add_property("courseName", &Corso::getCourseName, &Corso::setCourseName)
        .add_property("days", &Corso::getDays, &Corso::setDays)
        .add_property("monthlyCost", &Corso::getMonthlyCost, &Corso::setMonthlyCost)
        .add_property("instructorId", &Corso::getInstructorId, &Corso::setInstructorId);

    class_<Membership, boost::noncopyable>("Membership", init<string, int>())
        .add_property("courseName", &Membership::getCourseName, &Membership::setCourseName)
        .add_property("userId", &Membership::getUserId, &Membership::setUserId);
}


