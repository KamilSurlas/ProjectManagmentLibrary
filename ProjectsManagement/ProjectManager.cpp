#include "ProjectManager.h"

ProjectManager* ProjectManager::m_projectManager = nullptr;

ProjectManager* ProjectManager::getInstance()
{
	if (m_projectManager == nullptr)
		m_projectManager = new ProjectManager();

	return m_projectManager;
}

void ProjectManager::editName(TaskProject& target, string name)
{
	!name.empty() ? target.setName(name) : throw invalid_argument("Provided task name is empty");
}

void ProjectManager::editDescription(TaskProject& target, string desc)
{
	!desc.empty() ? target.setDescription(desc) : throw invalid_argument("Provided description is empty");
}

Project& ProjectManager::create(const std::string& name, const std::string& desc, Date projectStartDate, Date projectFinishDate)
{
	Project* p = new Project(name, desc, projectStartDate, projectFinishDate);
	m_projects.push_back(p);
	return *p;
}

bool ProjectManager::ifProjectExists(Project& project)
{
	return (std::find(m_projects.begin(), m_projects.end(), &project) != m_projects.end());
}

void ProjectManager::assignUserToProject(Project& targetProject, User& user)
{
	if (!ifProjectExists(targetProject))
	{
		throw invalid_argument("Project: " + targetProject.m_name + "does not exist");
	}
	isUserAssignedToProject(targetProject, user) ? throw invalid_argument("User: " + user.getName() + " " + user.getSurname() + " is already assign to project: " + targetProject.m_name) : targetProject.m_users.push_back(&user);
}

void ProjectManager::removeUserFromProject(Project& targetProject, User& user)
{
	if (!ifProjectExists(targetProject))
	{
		throw invalid_argument("Project: " + targetProject.m_name + "does not exist");
	}
	isUserAssignedToProject(targetProject, user) ? throw invalid_argument("User: " + user.getName() + " " + user.getSurname() + " is already assign to project: " + targetProject.m_name) : remove(targetProject.m_users.begin(), targetProject.m_users.end(), &user);
}

void ProjectManager::assignManagerToProject(Project& targetProject, User& manager)
{
	if (!ifProjectExists(targetProject))
	{
		throw invalid_argument("Project: " + targetProject.m_name + "does not exist");
	}
	targetProject.m_manager == nullptr ? targetProject.m_manager = &manager : throw invalid_argument("Project: " + targetProject.m_name + "already has manager assigned");
}

void ProjectManager::removeManagerFromProject(Project& targetProject, User& manager)
{
	if (!ifProjectExists(targetProject))
	{
		throw invalid_argument("Project: " + targetProject.m_name + "does not exist");
	}
	!(targetProject.m_manager == nullptr) ? targetProject.m_manager = nullptr : throw invalid_argument("Project: " + targetProject.m_name + "does not have manager assigned to it");
}

bool ProjectManager::isUserAssignedToProject(Project& targetProject, User& user) const
{
	return (std::find(targetProject.m_users.begin(), targetProject.m_users.end(), &user) != targetProject.m_users.end());
}
