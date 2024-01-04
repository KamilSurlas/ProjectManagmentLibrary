#include "Task.h"

Task::Task(const std::string& name, 
	unsigned int startDay, unsigned int startMonth, unsigned int startYear, unsigned int startHour, unsigned int startMin, 
	unsigned int endDay, unsigned int endMonth, unsigned int endYear, unsigned int endHour, unsigned int endMin)
	:m_taskStartDate(startDay, startMonth, startYear, startHour, startMin),
	m_taskFinishDate(endDay, endMonth, endYear, endHour, endMin),
	m_taskCreationDate(Date::getCurrentDate())
{}

void Task::editStartTime(unsigned int hour, unsigned int min)
{
	m_taskStartDate.editTime(hour, min);
}

void Task::editFinishTime(unsigned int hour, unsigned int min)
{
	m_taskFinishDate.editTime(hour, min);
}

void Task::editStartDate(unsigned int year, unsigned int month, unsigned int day)
{
	m_taskStartDate.editDate(year, month, day);
}

void Task::editFinishDate(unsigned int year,unsigned int month,unsigned int day)
{
	m_taskFinishDate.editDate(year, month, day);
}



