#pragma once
#include "Task.h"
class TaskManager
{
private:
	bool isUserAssignedToTask(Task& targetTask, User& user) const;
	bool isManagerAssignedToTask(Task& targetTask, User& manager) const;
protected:
	static TaskManager* m_taskManager;
protected:
	TaskManager() {

	}
public:
	TaskManager(TaskManager &other) = delete;
	TaskManager(TaskManager &&other) = delete;
	void operator=(TaskManager& other) = delete;
	void operator=(TaskManager&& other) = delete;

	static TaskManager* getInstance();

	void assignUserToTask(Task& targetTask, User& user);
	void removeUserFromTask(Task& targetTask, User& user);
	void assignManagerToTask(Task& targetTask, User& manager);
	void removeManagerFromTask(Task& targetTask, User& manager);
	void editTaskName(Task& targetTask, string name);
	void editTaskDescription(Task& targetTask, string desc);
};

