#include "FileHandler.h"

std::string* FileHandler::createFileName()
{
	std::time_t currentTime = std::time(nullptr);

	std::tm timeInfo;
	if (localtime_s(&timeInfo, &currentTime) != 0) {
		throw std::runtime_error("Error converting time.");
	}

	int hours = timeInfo.tm_hour;
	int min = timeInfo.tm_min;
	int day = timeInfo.tm_mday;
	int mon = timeInfo.tm_mon + 1;
	int year = timeInfo.tm_year + 1900;

	std::string* fileName = new std::string("projects-" + std::to_string(hours) + "-" + std::to_string(min) + "-"
		+ std::to_string(day) + "-" + std::to_string(mon) + "-" + std::to_string(year));

	return fileName;
}

void FileHandler::saveFile(CustomAllocator<Project>& data, std::string* fileName)
{
	auto pm = ProjectManager::getInstance();
	json j;

	std::ofstream file(*fileName + ".json");

	for (int i = 0; i < data.getSize(); i++) {
		json projectJson;
		projectJson["projectName"] = data[i]->getName();
		projectJson["projectManager"] = data[i]->getManager() == nullptr ? "" : data[i]->getManager()->getMail();
		projectJson["description"] = data[i]->getDescritpion(); 
		projectJson["creationDate"] = data[i]->getCreationDate().getDateTimeAsString();
		projectJson["startDate"] = data[i]->getStartDate().getDateTimeAsString();
		projectJson["finishDate"] = data[i]->getFinishDate().getDateTimeAsString();
	
		json participantsJson;
		for (size_t j = 0; j < data[i]->getAllParticipants().getSize(); j++)
		{
			json userJson;
			userJson["name"] = data[i]->getAllParticipants()[j]->getName();
			userJson["surname"] = data[i]->getAllParticipants()[j]->getSurname();
			userJson["email"] = data[i]->getAllParticipants()[j]->getMail();
			userJson["nickname"] = data[i]->getAllParticipants()[j]->getUsername();
			if (!data[i]->getAllParticipants()[j]->getPhoneNumber().empty())
				userJson["phoneNumber"] = data[i]->getAllParticipants()[j]->getPhoneNumber();

			participantsJson.push_back(userJson);
		}
		projectJson["participants"] = participantsJson;
		json tasksJson;
		for (size_t t = 0; t < data[i]->getTasks().getSize(); t++)
		{
			json taskJson;
			taskJson["name"] = data[i]->getTasks()[t]->getName();
			taskJson["finishDate"] = data[i]->getTasks()[t]->getFinishDate().getDateTimeAsString();
			taskJson["startDate"] = data[i]->getTasks()[t]->getStartDate().getDateTimeAsString();
			taskJson["creationDate"] = data[i]->getTasks()[t]->getCreationDate().getDateTimeAsString();
			taskJson["description"] = data[i]->getTasks()[t]->getDescritpion();

			json taskParticipantsJson;
			for (size_t p = 0; p < data[i]->getTasks()[t]->getAllUsers().getSize(); p++)
			{
				json oneTaskParticipantJson;
				oneTaskParticipantJson["email"] = data[i]->getTasks()[t]->getAllUsers()[p]->getMail();
				taskParticipantsJson.push_back(oneTaskParticipantJson);
			}
			taskJson["taskParticipants"] = taskParticipantsJson;

			json taskLeadersJson;
			for (size_t p = 0; p < data[i]->getTasks()[t]->getAllLeaders().getSize(); p++)
			{
				json oneTaskLeaderJson;
				oneTaskLeaderJson["email"] = data[i]->getTasks()[t]->getAllLeaders()[p]->getMail();
				taskLeadersJson.push_back(oneTaskLeaderJson);
			}
			taskJson["taskLeaders"] = taskLeadersJson;
			tasksJson.push_back(taskJson);
		}			
		projectJson["tasks"] = tasksJson;

		j.push_back(projectJson);
	}

	file << std::setw(4) << j;
	file.close();

	delete fileName;
}

void FileHandler::saveCSVFile(std::string* fileName)
{
	auto pm = ProjectManager::getInstance();
	string outputString = pm->printProjects();
	
	std::ofstream file(*fileName + ".csv");

	if (file.is_open()) {
		file << outputString;

		file.close();
	}
	else {
		std::cerr << "Failed opening file" << std::endl;
	}

	delete fileName;
}
