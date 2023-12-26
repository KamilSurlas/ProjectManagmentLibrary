#pragma once
class TaskManager
{
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

	//void addUserToTask();
};

