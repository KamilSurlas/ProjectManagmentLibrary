#pragma once
#include <stdexcept>
#include <ctime>
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
public:
	static Date getCurrentDate();
	Date(unsigned int d, unsigned int m, unsigned int y, unsigned int h, unsigned int min); 
	void editTime(unsigned int hour, unsigned int min); 
	void editDate(unsigned int year, unsigned int month, unsigned int day); 
};

