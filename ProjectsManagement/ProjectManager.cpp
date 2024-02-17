#include "ProjectManager.h"

ProjectManager* ProjectManager::m_projectManager = nullptr;

bool ProjectManager::isTaskAssignedToProject(Project& project, Task& task)
{
	return project.m_tasks.isAssigned(task);
}

ProjectManager* ProjectManager::getInstance()
{
	if (m_projectManager == nullptr)
		m_projectManager = new ProjectManager();

	return m_projectManager;
}
Project& ProjectManager::createProject(const std::string& name, const std::string& desc, Date projectStartDate, Date projectFinishDate)
{
	Project* p = new Project(name, desc, projectStartDate, projectFinishDate);
	m_projects.addElement(*p);
	return *p;
}
string ProjectManager::printProject(Project& project)
{
	return project.print();
}
string ProjectManager::printProjects()
{
	string text;
	for (int i = 0; i < m_projects.getSize(); i++)
	{
		text += m_projects[i].print() + "\n";
	}

	return text;
}

void ProjectManager::changeFinishDate(Project& project, Date newDate)
{
	project.setFinishDate(newDate);
}

void ProjectManager::changeStartDate(Project& project, Date newDate)
{
	project.setStartDate(newDate);
}

void ProjectManager::changeFinishDate(Project& project, Task& task, Date newDate)
{
	if (isTaskAssignedToProject(project, task))
	{
		project.changeTaskFinishDate(task, newDate);
	}
	else
	{
		throw invalid_argument("Project: " + project.getName() + " does not contains task: " + task.getName());
	}
}

void ProjectManager::changeStartDate(Project& project, Task& task, Date newDate)
{
	if (isTaskAssignedToProject(project, task))
	{
		project.changeTaskStartDate(task, newDate);
	}
	else
	{
		throw invalid_argument("Project: " + project.getName() + " does not contains task: " + task.getName());
	}
}

ProjectManager::~ProjectManager()
{
	if (m_projectManager != nullptr)
	{
		delete m_projectManager;
		m_projectManager = nullptr;
	}
}

CustomAllocator<Project>& ProjectManager::getProjects()
{
	return m_projects;
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


vector<User> ProjectManager::getAllParticipantsFromProject(Project& project)
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

Task& ProjectManager::assignTaskToProject(const std::string& name, const std::string& desc, Date taskStartDate, Date taskFinishDate, Project& project)
{
	Task* t = new Task(name, desc, taskStartDate, taskFinishDate);
	project.addTask(*t);
	return *t;
}
