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
	void removeUser(const User& usr) override;
	void addLeader(User& ldr);
	void removeLeader(const User& ldr);
	bool operator==(const Task& rhs);
	bool operator!=(const Task& rhs);
	Task& operator=(const Task& task);
	Task& operator=(Task&& task) noexcept;
	Task(const Task& task);
	Task(Task&& task) noexcept;
	string toString();

};

