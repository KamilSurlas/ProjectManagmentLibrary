#pragma once
#include <vector>
#include "User.h"
#include "Date.h"
#include "TaskProject.h"
class Task : public TaskProject
{
private:
	std::vector<User*> m_users;
	std::vector<User*> m_leaders;
	friend class TaskManager;
private:
	Task(const std::string& name, const std::string& desc, Date taskStartDate, Date taskFinishDate);	
};

