#include "ProjectManager.h"

ProjectManager* ProjectManager::m_projectManager = nullptr;

ProjectManager* ProjectManager::getInstance()
{
	if (m_projectManager == nullptr)
		m_projectManager = new ProjectManager();

	return m_projectManager;
}
Project& ProjectManager::create(const std::string& name, const std::string& desc, Date projectStartDate, Date projectFinishDate)
{
	Project* p = new Project(name, desc, projectStartDate, projectFinishDate);
	m_projects.push_back(p);
	return *p;
}
bool ProjectManager::isTaskAssignedToProject(Project& project, Task& task) const 
{
	return (std::find(project.m_tasks.begin(), project.m_tasks.end(), &task) != project.m_tasks.end());
}

void ProjectManager::assignUserToTask(Project& project, Task& task, User& user)
{
	if (isTaskAssignedToProject(project,task))
	{
		project.assignUserToTask(task,user);
	}
	else
	{
		throw invalid_argument("Project: " + project.getName() + " does not contains task: " + task.getName());
	}
}

void ProjectManager::removeUserFromTask(Project& project, Task& task, User& user)
{
	if (isTaskAssignedToProject(project, task))
	{
		project.removeUserFromTask(task, user);
	}
	else
	{
		throw invalid_argument("Project: " + project.getName() + " does not contains task: " + task.getName());
	}
}

void ProjectManager::assignLeaderToTask(Project& project, Task& task, User& leader)
{
	if (isTaskAssignedToProject(project, task))
	{
		project.assignLeaderToTask(task, leader);
	}
	else
	{
		throw invalid_argument("Project: " + project.getName() + " does not contains task: " + task.getName());
	}
}

void ProjectManager::removeLeaderFromTask(Project& project, Task& task, User& leader)
{
	if (isTaskAssignedToProject(project, task))
	{
		project.removeLeaderFromTask(task, leader);
	}
	else
	{
		throw invalid_argument("Project: " + project.getName() + " does not contains task: " + task.getName());
	}
}

void ProjectManager::removeTask(Project& project, Task& task)
{
	if (isTaskAssignedToProject(project, task))
	{
		project.removeTask(task);
	}
	else
	{
		throw invalid_argument("Project: " + project.getName() + " does not contains task: " + task.getName());
	}
}

void ProjectManager::removeAllTasks(Project& project)
{
	project.removeAllTasks();
}

vector<User*> ProjectManager::getUsersFromProject(Project& project)
{
	if (project.m_users.size() > 0)
	{
		return project.m_users;
	}
}

vector<User*> ProjectManager::getAllParticipantsFromProject(Project& project)
{
	return project.getAllParticipants();
}

void ProjectManager::editProjectName(Project& project, string name)
{
	!name.empty() ? project.setName(name) : throw invalid_argument("Provided project name is empty");
}

void ProjectManager::editTaskName(Project& project, Task& task, string name)
{
	if (isTaskAssignedToProject(project,task))
	{
		!name.empty() ? task.setName(name) : throw invalid_argument("Provided task name is empty");
	}
	else
	{
		throw invalid_argument("Project: " + project.getName() + " does not contains task: " + task.getName());
	}
}

void ProjectManager::editProjectDescription(Project& project, string desc)
{
	!desc.empty() ? project.setDescription(desc) : throw invalid_argument("Provided project description is empty");
}

void ProjectManager::editTaskDescription(Project& project, Task& task, string desc)
{
	if (isTaskAssignedToProject(project, task))
	{
		!desc.empty() ? task.setDescription(desc) : throw invalid_argument("Provided task description is empty");
	}
	else
	{
		throw invalid_argument("Project: " + project.getName() + " does not contains task: " + task.getName());
	}
}
