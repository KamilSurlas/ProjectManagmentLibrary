#pragma once
#include <vector>
#include "Task.h"
#include "User.h"
#include "Date.h" 
#include "TaskProject.h"
class Project : public TaskProject
{
private: 
	std::vector<Task*> m_tasks;
	std::vector<User*> m_users;
	User* m_manager;
	friend class ProjectManager;
	Project(const std::string& name, const std::string& desc, Date projectStartDate, Date projectFinishDate);
public:
	std::vector<User> getAllParticipants();
};

