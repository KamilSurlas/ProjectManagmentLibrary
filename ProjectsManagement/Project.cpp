#include "Project.h"
#include "CustomException.h"

bool Project::isUserAssignedToTask(Task& task, User& user) const
{
	return false;
}

bool Project::isLeaderAssignedToTask(Task& task, User& leader) const
{
	return false;
}

bool Project::isUserAssignedToProject(User& user) const
{
	return false;
}

Project::Project(const std::string& name, const std::string& desc, Date projectStartDate, Date projectFinishDate)
	:TaskProject(name,desc,projectFinishDate,projectFinishDate)
{

}

void Project::addTask(Task& task)
{
	if (m_finishDate < task.getFinishDate() || m_creationDate > task.getCreationDate())
	{
		throw invalid_task("Provided task date (" + task.getFinishDate().getDateAsString() + ") is invalid (Project start date: " +m_startDate.getDateTimeAsString()+" project finish date : " + m_finishDate.getDateTimeAsString() + ")");
	}
	m_tasks.push_back(&task);
}
void Project::removeTask(Task& task)
{

}

void Project::removeAllTasks()
{
}

void Project::addUser(User& user)
{
	m_users.push_back(&user);
}

void Project::removeUser(User& user)
{
}

void Project::assignManager(User& manager)
{
	if (m_manager == nullptr)
	{
		m_manager = &manager;
	}
}

void Project::removeManager()
{
	if (m_manager != nullptr)
	{
		m_manager == nullptr;
	}
}

void Project::assignUserToTask(Task& task, User& user)
{
	task.addUser(user);
}

void Project::removeUserFromTask(Task& task, User& user)
{
	task.removeUser(user);
}

void Project::assignLeaderToTask(Task& task, User& leader)
{
	task.addLeader(leader);
}

void Project::removeLeaderFromTask(Task& task, User& leader)
{
	task.removeLeader(leader);
}

vector<User*> Project::getAllParticipants()
{
	return vector<User*>();
}

string Project::print()
{
	return string();
}

