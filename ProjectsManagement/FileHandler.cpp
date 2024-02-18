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

		//auto participants = data[i]->getAllParticipants();

		//for (int k = 0; k < participants.getSize(); k++) {
		//	// Create a JSON object for each participant
		//	json user;
		//	user["name"] = participants[k]->getName();

		//	projectJson.push_back(user);
		//}


		// Add the project JSON object to the main JSON array
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
