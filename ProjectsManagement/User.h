#pragma once
#include <string>
#include <stdexcept>
#include <regex>

using std::string;
using std::invalid_argument;
using std::regex;

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
	void setName(const string& newName);
	void setSurname(const string& newSurname);
	void setMail(const string& newMail);
	void setUsername(const string& newUsername);
	void setPhoneNumber(const string& newPhoneNumber);

//Methods
private:
	bool isValidPhoneNumber(const string& phoneNumber);
	bool isValidName(const string& name);


};



