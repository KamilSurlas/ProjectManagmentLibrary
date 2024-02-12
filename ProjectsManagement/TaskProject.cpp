#include "TaskProject.h"

TaskProject::TaskProject(const std::string& name, const std::string& desc, Date startDate, Date finishDate)
	:m_name(name),
	m_description(desc),
	m_startDate(startDate),
	m_finishDate(finishDate)
{
}
