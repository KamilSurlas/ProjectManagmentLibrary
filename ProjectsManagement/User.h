#pragma once
#include <string>
#include <stdexcept>
#include <regex>
#include "Task.h"

using std::string;
using std::invalid_argument;
using std::regex;
using std::vector;

class User
{
//Fields
private:
	string m_name;
	string m_surname;
	string m_mail;
	string m_username;
	string m_phoneNumber;

	//Tu mozna zrobic tablice wskaznikow zamiast vectora pewnie lepsza wydajnosc xppp
	vector<Task*> m_tasks;
public:
	User(string name, string surname, string mail, string username, string phoneNumber, Task* task);
	User(string name, string surname, string mail, string username, string phoneNumber);
	User(string name, string surname, string mail, string username);

	void setName(const string& newName);
	void setSurname(const string& newSurname);
	void setMail(const string& newMail);
	void setUsername(const string& newUsername);
	void setPhoneNumber(const string& newPhoneNumber);

	void assignTask(Task* task);
	void unassignTask(Task* task);
//Methods
private:
	bool isValidName(const string& name);
	bool isValidSurname(const string& surname);
	bool isValidMail(const string& mail);
	bool isValidUsername(const string& username);
	bool isValidPhoneNumber(const string& phoneNumber);
	bool isUserUnassignedFromTask(const Task* task);


};



