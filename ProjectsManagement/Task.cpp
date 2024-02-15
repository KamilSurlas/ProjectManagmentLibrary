#include "Task.h"

Task::Task(const std::string& name, const std::string& desc, Date startDate, Date finishDate)
	:TaskProject(name,desc,startDate,finishDate)
{}

void Task::addUser(User & usr)
{
	m_users.addElement(usr);
}

void Task::removeUser(const User& usr)
{
	m_users.removeElement(usr);
}

void Task::addLeader(User& ldr)
{
	m_users.addElement(ldr);
}

void Task::removeLeader(const User& ldr)
{
	m_users.removeElement(ldr);
}



