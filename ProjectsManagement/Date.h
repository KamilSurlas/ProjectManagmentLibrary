#pragma once
#include <stdexcept>
#include <ctime>
#include <string>
class Date
{
	unsigned int m_day;
	unsigned int m_month;
	unsigned int m_year;
	unsigned int m_hour;
	unsigned int m_min;

private:
	bool isValidDate(unsigned int day, unsigned int month, unsigned int year); 
	bool isValidTime(unsigned int hour, unsigned int minute);
	std::string addLeadingZero(unsigned int value);
public:
	static Date getCurrentDate();
	Date(unsigned int d, unsigned int m, unsigned int y, unsigned int h, unsigned int min);
	Date() {}
	void editTime(unsigned int hour, unsigned int min); 
	void editDate(unsigned int year, unsigned int month, unsigned int day); 
	std::string getDateAsString();
	std::string getDateTimeAsString();
	bool operator<(const Date& date);
	bool operator>(const Date& date);
	bool operator==(const Date& date);
	bool operator!=(const Date& date);
};

