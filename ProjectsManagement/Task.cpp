#include "Task.h"

Task::Task(const std::string& name, Date taskStartDate, Date taskFinishDate)
	:m_taskStartDate(taskStartDate),
	m_taskFinishDate(taskFinishDate),
	m_taskCreationDate(Date::getCurrentDate())
{}



