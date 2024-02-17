//#include "FileHandler.h"
//#include "CustomAllocator.cpp"
//
//std::string* FileHandler::createFileName()
//{
//	std::time_t currentTime = std::time(nullptr);
//
//	std::tm timeInfo;
//	if (localtime_s(&timeInfo, &currentTime) != 0) {
//		throw std::runtime_error("Error converting time.");
//	}
//
//	int hours = timeInfo.tm_hour;
//	int min = timeInfo.tm_min;
//	int day = timeInfo.tm_mday;
//	int mon = timeInfo.tm_mon + 1;
//	int year = timeInfo.tm_year + 1900;
//
//	std::string* fileName = new std::string("projects-" + std::to_string(hours) + "-" + std::to_string(min) + "-"
//		+ std::to_string(day) + "-" + std::to_string(mon) + "-" + std::to_string(year));
//
//	return fileName;
//}
//
//void FileHandler::saveFile(const std::vector<Task*>& data, std::string* fileName)
//{
//	//Zrobione na wskazniku, zeby przy ewentualnej awarii jak najszybciej sie zapisalo
//	if (data.size() > 0) {
//		json j;
//		for (auto i : data) {
//			j["TaskName"] = i->getName();
//			j["TaskDescription"] = i->getDescritpion();
//			j["CreationDate"] = i->getCreationDate().getDateTimeAsString();
//			//j[""]
//		}
//		
//		std::ofstream file(*fileName + ".json");
//		file << j;
//	}
//		
//
//	delete fileName;
//}
//
//void FileHandler::saveCSVFile(ProjectManager& pm, std::string* fileName)
//{
//	string xd = pm.printProjects();
//	std::ofstream plik("test.txt");
//
//	if (plik.is_open()) {
//		// Zapisz zmodyfikowany tekst do pliku CSV
//		plik << xd << std::endl;
//
//		// Zamknij plik
//		plik.close();
//
//		std::cout << "Dane zapisane do pliku: " << "test.txt" << std::endl;
//	}
//	else {
//		std::cerr << "B³¹d podczas otwierania pliku do zapisu." << std::endl;
//	}
//}
