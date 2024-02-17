#pragma once
// Interface for Project Manager
#include <string>
#include "Project.h"
using namespace std;
class Manager
{
protected:
	virtual void editProjectName(Project& project, string name) = 0;
	virtual void editTaskName(Project& project, Task& task, string name) = 0;
	virtual void editProjectDescription(Project& project, string desc) =0;
	virtual void editTaskDescription(Project& project, Task& task, string desc) =0;
	virtual void assignUserToTask(Project& project, Task& task, User& user) = 0;
	virtual void removeUserFromTask(Project& project, Task& task, User& user) = 0;
	virtual void assignLeaderToTask(Project& project, Task& task, User& leader) = 0;
	virtual void removeLeaderFromTask(Project& project, Task& task, User& leader) = 0;
	virtual void removeTask(Project& project, Task& task) = 0;
	virtual void removeAllTasks(Project& project) = 0;
	virtual vector<User> getAllParticipantsFromProject(Project& project) = 0;
	virtual void assignUserToProject(Project& project, User& user) = 0;
	virtual void removeUserFromProject(Project& project, User& user) = 0;
	virtual void assignManagerToProject(Project& project, User& manager) =0;
	virtual void removeManagerFromProject(Project& project, User& manager)=0;
	virtual void assignTaskToProject(Project& project, Task& task) = 0;
	virtual Task& assignTaskToProject(const std::string& name, const std::string& desc, Date taskStartDate, Date taskFinishDate, Project& project) = 0;
	virtual Project& createProject(const std::string& name, const std::string& desc, Date projectStartDate, Date projectFinishDate) = 0;
	virtual bool isTaskAssignedToProject(Project& project, Task& task) = 0;
	virtual void changeFinishDate(Project& project, Date newDate) = 0;
	virtual void changeStartDate(Project& project, Date newDate) = 0;
	virtual void changeFinishDate(Project& project, Task& task, Date newDate) = 0;
	virtual void changeStartDate(Project& project, Task& task, Date newDate) = 0;
	virtual string printProject(Project& project) = 0;
	virtual string printProjects() = 0;
public:
	virtual ~Manager() {}
};

