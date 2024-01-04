#include "Task.h"

Task::Task(const std::string& name, 
	unsigned int startDay, unsigned int startMonth, unsigned int startYear, unsigned int startHour, unsigned int startMin, 
	unsigned int endDay, unsigned int endMonth, unsigned int endYear, unsigned int endHour, unsigned int endMin)
	:m_taskStartDate(startDay, startMonth, startYear, startHour, startMin),
	m_taskFinishDate(endDay, endMonth, endYear, endHour, endMin),
	m_taskCreationDate(getCurrentDate())
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

Task::Date Task::getCurrentDate()
{
	std::time_t currentTime = std::time(nullptr);

	std::tm timeInfo;
	if (localtime_s(&timeInfo, &currentTime) != 0) {
		throw std::runtime_error("Error converting time.");
	}

	int hours = timeInfo.tm_hour;
	int min = timeInfo.tm_min;
	int day = timeInfo.tm_mday;
	int mon = timeInfo.tm_mon + 1;
	int year = timeInfo.tm_year + 1900;

	return Date(day, mon, year, hours, min);
}
void Task::editTaskName(Task& targetTask, string name)
{
	!name.empty() ? targetTask.m_taskName = name : throw invalid_argument("Provided task name is empty");
}

void Task::editTaskDescription(Task& targetTask, string desc)
{
	!desc.empty() ? targetTask.m_taskDescription = desc : throw invalid_argument("Provided task description is empty");
}
