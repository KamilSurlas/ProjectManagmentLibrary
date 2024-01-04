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
		void editTime(unsigned int hour,unsigned int min) {
			isValidTime(hour, min) ? m_min = min, m_hour = hour : throw std::invalid_argument("Invalid time values");
		}
		void editDate(unsigned int year, unsigned int month, unsigned int day) {
			isValidDate(day,month,year) ? m_year = year, m_month = month, m_day = day : throw std::invalid_argument("Invalid date values");
		}
	};


private:
	std::vector<User*> m_users;
	std::vector<User*> m_managers;
	std::string m_taskName;
	std::string m_taskDescription;
	Date m_taskCreationDate;
	Date m_taskFinishDate;
	Date m_taskStartDate;

	Date getCurrentDate();
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

