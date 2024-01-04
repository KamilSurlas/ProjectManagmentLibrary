#pragma once
#include <vector>
#include "User.h"
class Task
{
private:
	std::vector<User> m_users;
	std::vector<User> m_managers;
	friend class TaskManager;
};

