#pragma once
#include <vector>
#include "User.h"
class Task
{
private:
	class Date
	{
		unsigned int m_day;
		unsigned int m_month;
		unsigned int m_year;
		unsigned int m_hour;
		unsigned int m_min;

	private:
		bool isValidDate(unsigned int day, unsigned int month, unsigned int year) const {
			return (day >= 1 && day <= 31) && (month >= 1 && month <= 12) && (year >= 1000 && year <= 9999);
		}

		bool isValidTime(unsigned int hour, unsigned int minute) const {
			return hour < 24 && minute < 60;
		}
	public:
		Date(unsigned int d, unsigned int m, unsigned int y, unsigned int h, unsigned int min) {
			if (!isValidDate(d, m, y) || !isValidTime(h, min)) {
				throw std::invalid_argument("Invalid date or time values");
			}
			m_day = d;
			m_month = m;
			m_year = y;
			m_hour = h;
			m_min = min;
		}
	};


private:
	std::vector<User*> m_users;
	std::vector<User*> m_managers;
	std::string m_taskName;
	std::string m_taskDescription;

	friend class TaskManager;

public:
	Task(string taskName, string taskDescription, Date creationDate, Date taskStartDate, Date taskFinishDate);
	string getTaskName() { return m_taskName; }
};

