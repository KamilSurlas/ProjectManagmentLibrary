#pragma once
#include <string>
#include <stdexcept>
#include <regex>

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

public:
	User(string name, string surname, string mail, string username, string phoneNumber);
	User(string name, string surname, string mail, string username);
	User() {}
	void setName(const string& newName);
	void setSurname(const string& newSurname);
	void setMail(const string& newMail);
	void setUsername(const string& newUsername);
	void setPhoneNumber(const string& newPhoneNumber);
	string getName() { return m_name; }
	string getSurname() { return m_surname; }
	string getMail() { return m_mail; }
	string getUsername(){ return m_username; }
	string getPhoneNumber() { return m_phoneNumber; }
	bool operator==(const User& user);
	bool operator!=(const User& user);
//Methods
private:
	bool isValidName(const string& name);
	bool isValidSurname(const string& surname);
	bool isValidMail(const string& mail);
	bool isValidUsername(const string& username);
	bool isValidPhoneNumber(const string& phoneNumber);
};



