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
	Task(const std::string& name, const std::string& desc, Date taskStartDate, Date taskFinishDate);
public:
	void addUser(User& usr);
	void removeUser(const User& usr);
	void addLeader(User& ldr);
	void removeLeader(const User& ldr);
};

