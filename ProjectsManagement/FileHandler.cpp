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
		projectJson["description"] = data[i]->getDescritpion(); 
		projectJson["creationDate"] = data[i]->getCreationDate().getDateTimeAsString();
		projectJson["startDate"] = data[i]->getStartDate().getDateTimeAsString();
		projectJson["finishDate"] = data[i]->getFinishDate().getDateTimeAsString();


		std::vector<User*> participants = data[i]->getAllParticipants().toVector();
		json participantsJson;
		for (const auto& participant : participants) {
			json userJson;
			userJson["name"] = participant->getName();  
			userJson["surname"] = participant->getSurname();
			userJson["email"] = participant->getMail();
			userJson["nickname"] = participant->getUsername();
			if (!participant->getPhoneNumber().empty())
				userJson["phoneNumber"] = participant->getPhoneNumber();

			participantsJson.push_back(userJson);
		}
		projectJson["participants"] = participantsJson;


		std::vector<Task*> tasks = data[i]->getTasks().toVector();
		json tasksJson;
		for (const auto& task : tasks) {
			json taskJson;
			taskJson["name"] = task->getName();
			taskJson["finishDate"] = task->getFinishDate().getDateTimeAsString();
			taskJson["startDate"] = task->getStartDate().getDateTimeAsString();
			taskJson["creationDate"] = task->getCreationDate().getDateTimeAsString();
			taskJson["description"] = task->getDescritpion();
			

			std::vector<User*> taskParticipants = task->getAllUsers().toVector();
			json taskparticipantsJson;
			for (const auto& taskParticipant : taskParticipants) {
				json taskParticipantJson;
				taskParticipantJson["email"] = taskParticipant->getMail();
				taskparticipantsJson.push_back(taskParticipantJson);
			}
			taskJson["taskParticipants"] = taskparticipantsJson;


			std::vector<User*> taskLeaders = task->getAllLeaders().toVector();
			json taskLeadersJson;
			for (const auto& taskLeader : taskLeaders) {
				json taskLeaderJson;
				taskLeaderJson["email"] = taskLeader->getMail();
				taskLeadersJson.push_back(taskLeaderJson);
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
	std::cerr << outputString;
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
