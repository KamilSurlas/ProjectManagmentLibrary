#include "Date.h"


Date Date::getCurrentDate()
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

Date::Date(unsigned int d, unsigned int m, unsigned int y, unsigned int h, unsigned int min)
{
	if (!isValidDate(d, m, y) || !isValidTime(h, min)) {
		throw std::invalid_argument("Invalid date or time values");
	}
	m_day = d;
	m_month = m;
	m_year = y;
	m_hour = h;
	m_min = min;
}

void Date::editTime(unsigned int hour, unsigned int min)
{
	isValidTime(hour, min) ? m_min = min, m_hour = hour : throw std::invalid_argument("Invalid time values");
}

void Date::editDate(unsigned int year, unsigned int month, unsigned int day)
{
	isValidDate(day, month, year) ? m_year = year, m_month = month, m_day = day : throw std::invalid_argument("Invalid date values");
}

bool Date::isValidDate(unsigned int day, unsigned int month, unsigned int year)
{
	return (day >= 1 && day <= 31) && (month >= 1 && month <= 12) && (year >= 1000 && year <= 9999);
}

bool Date::isValidTime(unsigned int hour, unsigned int minute)
{
	return hour < 24 && minute < 60;
}


