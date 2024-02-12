#pragma once
#include "Task.h"
#include "FileHandler.h"
#include "Manager.h"
#include "Project.h"
class TaskManager : public Manager
{
private:
	bool isUserAssignedToTask(Task& targetTask, User& user) const;
	bool isLeaderAssignedToTask(Task& targetTask, User& leader) const;
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
	void editName(TaskProject& target, string name) override;
	void editDescription(TaskProject& targetT, string desc) override;
	static TaskManager* getInstance();

	void assignUserToTask(Task& targetTask, User& user);
	void removeUserFromTask(Task& targetTask, User& user);
	void assignLeaderToTask(Task& targetTask, User& leader);
	void removeLeaderFromTask(Task& targetTask, User& leader);
	// Mozna popisac wiecej creatow
	Task& create(const std::string& name, const std::string& desc, Date taskStartDate, Date taskFinishDate, Project& targetProject);
	bool removeTask(Task& targetTask, Project& targetProject);
	bool removeAllTasks(Project& targetProject);
	vector<User> getUsersFromTask(Task& targetTask, Project& targetProject);
};

