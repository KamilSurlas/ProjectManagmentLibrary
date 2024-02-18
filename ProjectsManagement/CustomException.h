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
class invalid_project : public CustomException
{
public:
	invalid_project(string message) :CustomException(message) {}
};
class allocator_data_empty : public CustomException
{
public:
	allocator_data_empty(string message) :CustomException(message) {}
};
class task_user_leader_conflict : public CustomException
{
public:
	task_user_leader_conflict(string message) :CustomException(message) {}
};