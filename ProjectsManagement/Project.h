#pragma once
#include "Task.h"
#include "User.h"
#include "Date.h" 
#include "TaskProject.h"
#include "CustomAllocator.h"
class Project : public TaskProject
{
private: 
	CustomAllocator<Task> m_tasks;
	CustomAllocator<User> m_users;
	User* m_manager = nullptr;
	friend class ProjectManager;
	Project(const std::string& name, const std::string& desc, Date projectStartDate, Date projectFinishDate);
	void addTask(Task& task);
	void removeTask(Task& task);
	void removeAllTasks();
	void addUser(User& user) override;
	void removeUser(const User& usr) override;
	void assignManager(User& manager);
	void removeManager();
	void assignUserToTask(Task& task, User& user);
	void removeUserFromTask(Task& task, User& user);
	void assignLeaderToTask(Task& task, User& leader);
	void removeLeaderFromTask(Task& task, User& leader);
	void changeTaskStartDate(Task& task, Date newDate);
	void changeTaskFinishDate(Task& task, Date newDate);

public:
	string print(char ch = '\n');
	Project() {}
	Project& operator=(const Project& project);
	bool operator==(const Project& project);
	bool operator!=(const Project& project);
	CustomAllocator<User>& getAllParticipants();
	Project& operator=(Project&& project) noexcept;
	Project(const Project& project) {};
	Project(Project&& project) noexcept;
};

