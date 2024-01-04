#pragma once
#include <vector>
#include "User.h"
#include "Date.h"
class Task
{
private:
	std::vector<User*> m_users;
	std::vector<User*> m_managers;
	std::string m_taskName;
	std::string m_taskDescription;
	Date m_taskCreationDate;
	Date m_taskFinishDate;
	Date m_taskStartDate;

	friend class TaskManager;
private:
	Task(const std::string& name, Date taskStartDate, Date taskFinishDate);	
public:
	string getTaskName() { return m_taskName; }
	string getTaskDescritpion() { return m_taskDescription; }
	Date getTaskStartDate() { return m_taskStartDate; }
	Date getTaskFinishDate() { return m_taskFinishDate; }
	Date getTaskCreationDate() { return m_taskCreationDate; }
};

