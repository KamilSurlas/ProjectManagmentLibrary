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
