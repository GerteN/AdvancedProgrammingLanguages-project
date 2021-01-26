#include "pch.h"
#include "db.h"
typedef std::vector<std::string> lista;

db::db() {
	m_conn = mysql_init(NULL);
}

db::~db() {}

void db::setConn(MYSQL* conn) {
	m_conn = conn;
}
void db::setResult(MYSQL_RES* result) {
	m_result = result;
}
void db::setRow(MYSQL_ROW row) {
	m_row = row;
}

MYSQL* db::getConn() {
	return m_conn;
}
MYSQL_RES* db::getResult() {
	return m_result;
}
MYSQL_ROW db::getRow() {
	return m_row;
}



void db::close(MYSQL* conn) {
	mysql_close(conn);
}

//connect without db already created
void db::connect(MYSQL* conn, const char* host, const char* user, const char* password, int port) {
	if (mysql_real_connect(conn, host, user, password, NULL, port, NULL, 0) == NULL)
	{
		throw std::runtime_error("Connection Error with the db");
		mysql_close(conn);
		exit(1);
	}
}


//connect if db already created
void db::connect(MYSQL* conn, const char* host, const char* user, const char* password, int port, std::string db) {
	if (mysql_real_connect(conn, host, user, password, db.c_str(), port, NULL, 0) == NULL) 
	{
		throw std::runtime_error("Connection Error with the db");
		mysql_close(conn);
		exit(1);
	}
}


//optional create a db
void db::createDB(MYSQL* conn, std::string db) {
	std::string query = "CREATE DATABASE " + db;
	if (mysql_query(conn, query.c_str()) == NULL)
	{
		std::string error = "unable to create db with name " + db;
		throw std::runtime_error(error);
		mysql_close(conn);
		exit(1);
	}
}

//query without retruning
void db::queryDB(MYSQL* conn, const char* query) {
	if (mysql_query(conn, query))
	{
		std::string error = "unable to query db with name " + std::string(conn->db) + "; query: " + std::string(query);
		throw std::runtime_error(error);
		mysql_close(conn);
		exit(1);
	}
}

//query with returning values from db
lista db::queryDB(MYSQL* conn, const char* query, bool insert) {
	if (mysql_query(conn, query)) 
	{
		std::string error = "unable to query db with name " + std::string(conn->db) + "; query: " + std::string(query);
		throw std::runtime_error(error);
		mysql_close(conn);
		exit(1);
	}
	m_result = mysql_store_result(conn);
	unsigned int num_fields;
	unsigned int i;
	lista last;
	num_fields = mysql_num_fields(m_result);
	while ((m_row = mysql_fetch_row(m_result)))
	{
		unsigned long* lengths;
		lengths = mysql_fetch_lengths(m_result);
		std::string s = "";
		for (i = 0; i < num_fields; i++)
			s.append(m_row[i]).append(" ");
		last.push_back(s);
	}
	return last;

}
