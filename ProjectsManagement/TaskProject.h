#pragma once
#include <vector>
#include "User.h"
#include "Date.h"
class TaskProject
{
protected:
	std::string m_name;
	std::string m_description;
	Date m_creationDate = Date::getCurrentDate();
	Date m_finishDate;
	Date m_startDate;
public:
	TaskProject(const std::string& name, const std::string& desc, Date startDate, Date finishDate);
	string getName() { return m_name; }
	string getDescritpion() { return m_description; }
	Date getStartDate() { return m_creationDate; }
	Date getFinishDate() { return m_finishDate; }
	Date getCreationDate() { return m_startDate; }
	void setName(std::string name) { m_name = name; }
	void setDescription(std::string desc) { m_description = desc; }
	void setStartDate(Date startDate) { m_startDate = startDate; }
	void setFinishDate(Date finishDate) { m_finishDate = finishDate; }
	virtual ~TaskProject() {}
};

