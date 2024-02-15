#pragma once
#include <exception>
#include <string>
using namespace std;
class CustomException : public exception
{
	string errorMessage;
public:
	CustomException(string message) :errorMessage(message) {}
		const char* what() const noexcept override {
		return errorMessage.c_str();
	}
};
class invalid_task: public CustomException 
{
public:
	invalid_task(string message) :CustomException(message) {}
};
class invalid_date : public CustomException
{
public:
	invalid_date(string message) :CustomException(message) {}
};

class invalid_user : public CustomException
{
public:
	invalid_user(string message) :CustomException(message) {}
};