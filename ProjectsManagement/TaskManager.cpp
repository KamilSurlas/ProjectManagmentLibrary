#include "TaskManager.h"

TaskManager* TaskManager::m_taskManager = nullptr;

bool TaskManager::isUserAssignedToTask(Task& targetTask, User& user) const
{
	return (std::find(targetTask.m_users.begin(), targetTask.m_users.end(), &user) != targetTask.m_users.end());
}

bool TaskManager::isManagerAssignedToTask(Task& targetTask, User& manager) const
{
	return (std::find(targetTask.m_managers.begin(), targetTask.m_managers.end(), &manager) != targetTask.m_users.end());
}

TaskManager* TaskManager::getInstance()
{
	if (m_taskManager == nullptr)
		m_taskManager = new TaskManager();

	return m_taskManager;
}

void TaskManager::assignUserToTask(Task& targetTask, User& user)
{
	isUserAssignedToTask(targetTask, user) ? throw invalid_argument("User: " + user.getName() + " " + user.getSurname() + " is already assign to task: " + targetTask.m_taskName) : targetTask.m_users.push_back(&user);
}

void TaskManager::removeUserFromTask(Task& targetTask, User& user)
{
	remove(targetTask.m_users.begin(), targetTask.m_users.end(), &user);
}

void TaskManager::removeManagerFromTask(Task& targetTask, User& manager)
{
	remove(targetTask.m_managers.begin(), targetTask.m_users.end(), &manager);
}
Task& TaskManager::createTask(const std::string& name, Date taskStartDate, Date taskFinishDate)
{
	Task* t = new Task(name, taskStartDate, taskFinishDate);
	m_tasks.push_back(t);
	return *t;
}
void TaskManager::removeTask(Task* targetTask)
{
	remove(m_tasks.begin(), m_tasks.end(), targetTask);
	delete targetTask;
}
void TaskManager::removeAllTasks()
{
	for (auto i : m_tasks)
	{
		delete i;
	}
	m_tasks.clear();
}
void TaskManager::assignManagerToTask(Task& targetTask, User& manager)
{
	isManagerAssignedToTask(targetTask, manager) ? throw invalid_argument("Manager: " + manager.getName() + " " + manager.getSurname() + " is already assign to task: " + targetTask.m_taskName) : targetTask.m_managers.push_back(&manager);
}
void TaskManager::editTaskName(Task& targetTask, string name)
{
	!name.empty() ? targetTask.m_taskName = name : throw invalid_argument("Provided task name is empty");
}

void TaskManager::editTaskDescription(Task& targetTask, string desc)
{
	!desc.empty() ? targetTask.m_taskDescription = desc : throw invalid_argument("Provided task description is empty");
}

