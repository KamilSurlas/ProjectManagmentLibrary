#include "Project.h"

Project::Project(const std::string& name, const std::string& desc, Date projectStartDate, Date projectFinishDate)
	:TaskProject(name,desc,projectFinishDate,projectFinishDate)
{
}

std::vector<User> Project::getAllParticipants()
{
	std::vector<User> participants;
	for (const auto& task : m_tasks)
	{
	// TU TRZEBA POBRAC Z TASKOW USEROW
		
	}
	return participants;
}
