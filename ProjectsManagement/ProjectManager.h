#pragma once
#include "Manager.h"
#include "Project.h"
#include "CustomAllocator.h"
#include <vector>
class ProjectManager : public Manager
{
private:
	CustomAllocator<Project> m_projects;
	bool isTaskAssignedToProject(Project& project, Task& task) override;
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
	CustomAllocator<User>& getAllParticipantsFromProject(Project& project) override;
	void removeAllTasks(Project& project) override;
	void assignUserToProject(Project& project, User& user) override;
	void removeUserFromProject(Project& project, User& user) override;
	void assignManagerToProject(Project& project, User& manager) override;
	void removeManagerFromProject(Project& project, User& manager) override;
	void assignTaskToProject(Project& project, Task& task) override;
	Task* assignTaskToProject(const std::string& name, const std::string& desc, Date taskStartDate, Date taskFinishDate, Project& project) override;
	Project* createProject(const std::string& name, const std::string& desc, Date projectStartDate, Date projectFinishDate) override;
	string printProject(Project& project) override;
	string printProjects() override;
	void changeFinishDate(Project& project, Date newDate) override;
	void changeStartDate(Project& project, Date newDate) override;
	void changeFinishDate(Project& project, Task& task, Date newDate) override;
	void changeStartDate(Project& project, Task& task, Date newDate) override;
	void removeProject(Project& project) override;
	~ProjectManager();
	CustomAllocator<Project>& getProjects() override;
};

