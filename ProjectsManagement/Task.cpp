#include "Task.h"

Task::Task(const std::string& name, 
	unsigned int startDay, unsigned int startMonth, unsigned int startYear, unsigned int startHour, unsigned int startMin, 
	unsigned int endDay, unsigned int endMonth, unsigned int endYear, unsigned int endHour, unsigned int endMin)
	:m_taskStartDate(startDay, startMonth, startYear, startHour, startMin),
	m_taskFinishDate(endDay, endMonth, endYear, endHour, endMin),
	m_taskCreationDate(getCurrentDate())
{

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
