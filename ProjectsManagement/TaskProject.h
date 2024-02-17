#pragma once
#include "User.h"
#include "Date.h"
#include "CustomAllocator.h"
#include "CustomException.h"
class TaskProject
{
protected:
	std::string m_name;
	std::string m_description;
	Date m_creationDate = Date::getCurrentDate();
	Date m_finishDate;
	Date m_startDate;
	virtual void addUser(User& usr) = 0;
	virtual void removeUser(const User& usr) = 0;
	void setName(std::string name) { m_name = name; }
	void setDescription(std::string desc) { m_description = desc; }
public:
	TaskProject(const std::string& name, const std::string& desc, Date startDate, Date finishDate);
	string getName()  const { return m_name; }
	string getDescritpion()const { return m_description; }
	Date getStartDate()const { return m_creationDate; }
	Date getFinishDate() const { return m_finishDate; }
	Date getCreationDate() const { return m_startDate; }
	void setStartDate(Date startDate);
	void setFinishDate(Date finishDate);
	virtual ~TaskProject() {}
	//virtual 
	TaskProject() {}
};

