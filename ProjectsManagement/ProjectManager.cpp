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
string ProjectManager::printProject(Project& project)
{
	return project.print();
}
string ProjectManager::printProjects()
{
	string text;
	for (const auto& project : m_projects)
	{
		text += project->print() + "\n";
	}

	return text;
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
	throw invalid_argument("Project: " + project.m_name +"does not have any users assigned to it");
}

void ProjectManager::assignUserToProject(Project& project, User& user)
{
	project.addUser(user);
}

void ProjectManager::removeUserFromProject(Project& project, User& user)
{
	project.removeUser(user);
}

void ProjectManager::assignManagerToProject(Project& project, User& manager)
{
	project.assignManager(manager);
}

void ProjectManager::removeManagerFromProject(Project& project, User& manager)
{
	project.removeManager();
}

void ProjectManager::assignTaskToProject(const std::string& name, const std::string& desc, Date taskStartDate, Date taskFinishDate, Project& project)
{
	project.addTask(name, desc, taskStartDate, taskFinishDate);
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
void ProjectManager::assignTaskToProject(Project& project, Task& task)
{
	project.addTask(task);
}
