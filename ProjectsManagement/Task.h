#pragma once
#include "User.h"
#include "Date.h"
#include "TaskProject.h"
class Task : public TaskProject
{
private:
	CustomAllocator<User> m_users;
	CustomAllocator<User> m_leaders;
	friend class ProjectManager;
private:
	
	bool compareFields(const Task& task);
	
public:
	Task(const std::string name, const std::string desc, Date taskStartDate, Date taskFinishDate);
	Task() {}
	void addUser(User& usr) override;
	bool removeUser(const User& usr) override;
	void addLeader(User& ldr);
	bool removeLeader(const User& ldr);
	bool operator==(const Task& rhs);
	bool operator!=(const Task& rhs);
	Task& operator=(const Task& task) = delete;
	Task& operator=(Task&& task) noexcept = delete;
	Task(const Task& task) = delete;
	Task(Task&& task) noexcept = delete;
	string toString();

};

