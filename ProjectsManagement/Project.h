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
	bool isUserAssignedToTask(Task& task, User& user) const;
	bool isLeaderAssignedToTask(Task& task, User& leader) const;
	Project(const std::string& name, const std::string& desc, Date projectStartDate, Date projectFinishDate);
	void addTask(Task& task);
	void addTask(const std::string& name, const std::string& desc, Date taskStartDate, Date taskFinishDate);
	void removeTask(Task& task);
	void removeAllTasks();
	void addUser(User& user);
	void removeUser(User& user);
	void assignManager(Manager& manager);
	void removeManager();
	void assignUserToTask(Task& task, User& user);
	void removeUserFromTask(Task& task, User& user);
	void assignLeaderToTask(Task& task, User& leader);
	void removeLeaderFromTask(Task& task, User& leader);
	vector<User*> getAllParticipants();
};

