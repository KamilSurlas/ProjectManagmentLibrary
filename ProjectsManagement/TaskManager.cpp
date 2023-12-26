#include "TaskManager.h"

TaskManager* TaskManager::m_taskManager = nullptr;

TaskManager* TaskManager::getInstance()
{
	if (m_taskManager == nullptr)
		m_taskManager = new TaskManager();

	return m_taskManager;
}
