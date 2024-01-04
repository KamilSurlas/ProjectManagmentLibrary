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

public:
	Task(const std::string& name,
		unsigned int startDay, unsigned int startMonth, unsigned int startYear, unsigned int startHour, unsigned int startMin,
		unsigned int endDay, unsigned int endMonth, unsigned int endYear, unsigned int endHour, unsigned int endMin);
	void editStartDate(unsigned int year, unsigned int month,unsigned int day);
	void editFinishDate(unsigned int year,unsigned int month,unsigned int day);
	void editStartTime(unsigned int hour, unsigned int min);
	void editFinishTime(unsigned int hour, unsigned int min);
	
	string getTaskName() { return m_taskName; }
	string getTaskDescritpion() { return m_taskDescription; }
	Date getTaskStartDate() { return m_taskStartDate; }
	Date getTaskFinishDate() { return m_taskFinishDate; }
	Date getTaskCreationDate() { return m_taskCreationDate; }
};

