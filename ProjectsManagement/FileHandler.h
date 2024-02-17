#pragma once
#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
#include <chrono>
#include <time.h>
#include "Task.h"
#include "ProjectManager.h"

using json = nlohmann::json;
class FileHandler
{
public:
	//static std::string* createFileName();
	//static void saveFile(const std::vector<Task*>& data, std::string* fileName = createFileName());
	//static void saveCSVFile(ProjectManager& pm, std::string* fileName = createFileName());
};

