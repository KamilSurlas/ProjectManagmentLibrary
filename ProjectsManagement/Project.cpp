#include "Project.h"
#include "CustomException.h"


Project::Project(const std::string& name, const std::string& desc, Date projectStartDate, Date projectFinishDate)
	:TaskProject(name,desc,projectFinishDate,projectFinishDate)
{

}

void Project::addTask(Task& task)
{
	if (m_finishDate < task.getFinishDate() || m_creationDate > task.getCreationDate())
	{
		throw invalid_task("Provided task date (" + task.getFinishDate().getDateAsString() + ") is invalid (Project start date: " +m_startDate.getDateTimeAsString()+" project finish date : " + m_finishDate.getDateTimeAsString() + ")");
	}
	m_tasks.addElement(task);
}
void Project::removeTask(Task& task)
{
	m_tasks.removeElement(task);
}

void Project::removeAllTasks()
{
	m_tasks.removeAll();
}

void Project::addUser(User& user)
{
	m_users.addElement(user);
}

void Project::removeUser(const User& usr)
{
	m_users.removeElement(usr);
}

void Project::assignManager(User& manager)
{
	if (m_manager == nullptr)
	{
		m_manager = &manager;
	}
}

void Project::removeManager()
{
	if (m_manager != nullptr)
	{
		m_manager = nullptr;
	}
}

void Project::assignUserToTask(Task& task, User& user)
{
	if (m_users.isAssigned(user))
		task.addUser(user);
	else
		throw invalid_user("User is not assigned to project");
}

void Project::removeUserFromTask(Task& task, User& user)
{
	task.removeUser(user);
}

void Project::assignLeaderToTask(Task& task, User& leader)
{
	task.addLeader(leader);
}

void Project::removeLeaderFromTask(Task& task, User& leader)
{
	task.removeLeader(leader);
}

void Project::changeTaskStartDate(Task& task, Date newDate)
{
	if (m_startDate > newDate)
		throw invalid_date("Provided task's date is earlier than project's date");
	task.setStartDate(newDate);
}

void Project::changeTaskFinishDate(Task& task, Date newDate)
{
	if (m_finishDate < newDate)
		throw invalid_date("Provided task's date is later than project's date");
	task.setFinishDate(newDate);
}

string Project::print(char ch)
{
	string formattedText;
	
	formattedText += "Project name: " + this->m_name + "\n";
	formattedText += "All participants:\n";
	for (int i = 0; i < this->m_users.getSize(); i++) {
		formattedText += m_users[i].toString() + "\n";
	}

	formattedText += "Tasks:\n";
	for (size_t i = 0; i < this->m_tasks.getSize(); i++)
	{
		formattedText += m_tasks[i].toString();
	}

	return formattedText;
}


CustomAllocator<User>& Project::getAllParticipants()
{
	CustomAllocator<User> participants;
	for (int i = 0; i < m_users.getSize(); i++) {
		participants.addElement(m_users[i]);
	}

	return participants;
}

Project& Project::operator=(const Project& project)
{
	if (this != &project) {
		m_name = project.m_name;
		m_description = project.m_description;
		m_startDate = project.m_startDate;
		m_finishDate = project.m_finishDate;
		m_creationDate = project.m_creationDate;

		/*m_users = task.m_users;
		m_leaders = task.m_leaders;*/
	}
	return *this;
}

bool Project::operator==(const Project& project)
{
	return m_name == project.m_name &&
		m_description == project.m_description &&
		m_startDate == project.m_startDate &&
		m_finishDate == project.m_finishDate &&
		m_creationDate == project.m_creationDate &&
		m_users == project.m_users &&
		m_tasks == project.m_tasks;
}

bool Project::operator!=(const Project& project)
{
	return !(*this == project);
}

