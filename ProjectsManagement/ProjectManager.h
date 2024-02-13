#pragma once
#include "Manager.h"
#include "Project.h"
#include <vector>
class ProjectManager : public Manager
{
private:
	std::vector<Project*> m_projects;
protected:
	static ProjectManager* m_projectManager;
protected:
	ProjectManager() {

	}
public:
	static ProjectManager* getInstance();
	void editProjectName(Project& project, string name) override;
	void editTaskName(Project& project, Task& task, string name) override;
	void editProjectDescription(Project& project, string desc) override;
	void editTaskDescription(Project& project, Task& task, string desc) override;
	void assignUserToTask(Project& project, Task& task, User& user) override;
	void removeUserFromTask(Project& project, Task& task, User& user) override;
	void assignLeaderToTask(Project& project, Task& task, User& leader) override;
	void removeLeaderFromTask(Project& project, Task& task, User& leader) override;
	void removeTask(Project& project, Task& task) override;
	vector<User*> getUsersFromProject(Project& project) override;
	vector<User*> getAllParticipantsFromProject(Project& project) override;
	void removeAllTasks(Project& project) override;
	void assignUserToProject(Project& project, User& user) override;
	void removeUserFromProject(Project& project, User& user) override;
	void assignManagerToProject(Project& project, User& manager) override;
	void removeManagerFromProject(Project& project, User& manager) override;
	void assignTaskToProject(Project& project, Task& task) override;
	void assignTaskToProject(const std::string& name, const std::string& desc, Date taskStartDate, Date taskFinishDate, Project& project) override;
	Project& create(const std::string& name, const std::string& desc, Date projectStartDate, Date projectFinishDate) override;
	string printProject(Project& project) override;
	string printProjects() override;
private:
	bool isTaskAssignedToProject(Project& project, Task& task) const override;
};

