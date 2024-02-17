#include "TaskProject.h"

TaskProject::TaskProject(const std::string name, const std::string desc, Date startDate, Date finishDate)
	:m_name(name),
	m_description(desc),
	m_startDate(startDate),
	m_finishDate(finishDate)
{
}

void TaskProject::setStartDate(Date startDate)
{
	if (startDate < m_finishDate)
		this->m_startDate = startDate;
	else
		throw invalid_date("Wrong date provided");
}

void TaskProject::setFinishDate(Date finishDate)
{
	if (finishDate > m_startDate)
		this->m_finishDate = finishDate;
	else
		throw invalid_date("Wrong date provided");
}
