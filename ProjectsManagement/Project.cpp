#include "Project.h"

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
}

void Project::addTask(const std::string& name, const std::string& desc, Date taskStartDate, Date taskFinishDate)
{
}

void Project::removeTask(Task& task)
{
}

void Project::removeAllTasks()
{
}

void Project::addUser(User& user)
{
}

void Project::removeUser(User& user)
{
}

void Project::assignManager(User& manager)
{
}

void Project::removeManager()
{
}

void Project::assignUserToTask(Task& task, User& user)
{
}

void Project::removeUserFromTask(Task& task, User& user)
{
}

void Project::assignLeaderToTask(Task& task, User& leader)
{
}

void Project::removeLeaderFromTask(Task& task, User& leader)
{
}

vector<User*> Project::getAllParticipants()
{
	return vector<User*>();
}

string Project::print()
{
	return string();
}

