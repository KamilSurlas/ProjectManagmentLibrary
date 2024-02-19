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
	~FileHandler(){  }
	static std::string* createFileName();
	static void saveFile(CustomAllocator<Project>& data, std::string* fileName = createFileName());
	static void saveCSVFile(std::string* fileName = createFileName());
};

