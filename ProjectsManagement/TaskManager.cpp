#include "TaskManager.h"

TaskManager* TaskManager::m_taskManager = nullptr;

bool TaskManager::isUserAssignedToTask(Task& targetTask, User& user) const
{
	return (std::find(targetTask.m_users.begin(), targetTask.m_users.end(), &user) != targetTask.m_users.end());
}

bool TaskManager::isLeaderAssignedToTask(Task& targetTask, User& leader) const
{
	return (std::find(targetTask.m_leaders.begin(), targetTask.m_leaders.end(), &leader) != targetTask.m_users.end());
}

TaskManager* TaskManager::getInstance()
{
	if (m_taskManager == nullptr)
		m_taskManager = new TaskManager();

	return m_taskManager;
}

void TaskManager::assignUserToTask(Task& targetTask, User& user)
{
	isUserAssignedToTask(targetTask, user) ? throw invalid_argument("User: " + user.getName() + " " + user.getSurname() + " is already assign to task: " + targetTask.m_name) : targetTask.m_users.push_back(&user);
}


void TaskManager::removeUserFromTask(Task& targetTask, User& user)
{
	remove(targetTask.m_users.begin(), targetTask.m_users.end(), &user);
}

void TaskManager::removeLeaderFromTask(Task& targetTask, User& leader)
{
	remove(targetTask.m_leaders.begin(), targetTask.m_users.end(), &leader);
}
Task& TaskManager::create(const std::string& name, const std::string& desc, Date taskStartDate, Date taskFinishDate, Project& targetProject)
{
	Task* t = new Task(name, desc, taskStartDate, taskFinishDate);
	ProjectManager::getInstance()->assignTaskToProject(targetProject, *t);
	return *t;
}
bool TaskManager::removeTask(Task& targetTask, Project& targetProject)
{
	ProjectManager::getInstance().re
	// TU DODAC PO OGARNIECIU PROJECY MANAGERA
	/*remove(m_tasks.begin(), m_tasks.end(), targetTask);
	delete targetTask; */
	return false;
}
bool TaskManager::removeAllTasks(Project& targetProject)
{
	// PO NAPISANIU PROECY MANAGERA
	return 1;
	/*for (auto i : m_tasks)
	{
		delete i;
	}
	m_tasks.clear();*/
}
vector<User> TaskManager::getUsersFromTask(Task& targetTask, Project& targetProject)
{
	//potem
	return vector<User>();
}
void TaskManager::assignLeaderToTask(Task& targetTask, User& leader)
{
	isLeaderAssignedToTask(targetTask, leader) ? throw invalid_argument("Leader: " + leader.getName() + " " + leader.getSurname() + " is already assign to task: " + targetTask.m_name) : targetTask.m_leaders.push_back(&leader);
}
void TaskManager::editName(TaskProject& target, string name)
{
	!name.empty() ? target.setName(name) : throw invalid_argument("Provided task name is empty");
}

void TaskManager::editDescription(TaskProject& target, string desc)
{
	!desc.empty() ? target.setDescription(desc) : throw invalid_argument("Provided task description is empty");
}


