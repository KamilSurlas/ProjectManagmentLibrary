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
	void editName(TaskProject& target, string name) override;
	void editDescription(TaskProject& targetT, string desc) override;
	Project& create(const std::string& name, const std::string& desc, Date projectStartDate, Date projectFinishDate);
	void assignUserToProject(Project& targetProject, User& user);
	void removeUserFromProject(Project& targetProject, User& user);
	void assignManagerToProject(Project& targetProject, User& manager);
	void removeManagerFromProject(Project& targetProject, User& manager);
	void assignTaskToProject(Project& targetProject, Task& task);
private:
	bool ifProjectExists(Project& project);
	bool isUserAssignedToProject(Project& targetProject, User& user) const;
	bool isTaskAssignedToProject(Project& targetProject, Task& task) const;
};

