#include "Task.h"

Task::Task(const std::string name, const std::string desc, Date startDate, Date finishDate)
	:TaskProject(name,desc,startDate,finishDate)
{}

bool Task::compareFields(const Task & task)
{
	return this->m_name == task.m_name &&
		this->m_description == task.m_description &&
		this->m_creationDate == task.m_creationDate &&
		this->m_startDate == task.m_startDate &&
		this->m_finishDate == task.m_finishDate;
}

void Task::addUser(User & usr)
{
	m_users.addElement(&usr);
}

bool Task::removeUser(const User& usr)
{
	return m_users.removeElement(usr);
}

void Task::addLeader(User& ldr)
{
	m_leaders.addElement(&ldr);
}

bool Task::removeLeader(const User& ldr)
{
	return m_leaders.removeElement(ldr);
}

bool Task::operator==(const Task& rhs)
{
	if (this != &rhs)
	{
		return compareFields(rhs);
	}
	return true;
}

bool Task::operator!=(const Task& rhs)
{
	return !(*this == rhs);
}

string Task::toString()
{
	string formattedText;
	formattedText += "Name: " + this->m_name;
	formattedText += "Creation date: " + this->m_creationDate.getDateTimeAsString() + "\n";
	formattedText += "Start task date: " + this->m_startDate.getDateTimeAsString() + "\n";
	formattedText += "Finish task date: " + this->m_creationDate.getDateTimeAsString() + "\n";
	formattedText += "Name: " + this->m_name + "\n";
	formattedText += "Leaders:\n";
	for (int i = 0; i < m_leaders.getSize(); i++) {
		formattedText += m_leaders[i]->toString() + "\n";
	}

	formattedText += "Participants:\n";
	for (size_t i = 0; i < m_users.getSize(); i++)
	{
		formattedText += m_users[i]->toString() + "\n";
	}

	return formattedText;
}



