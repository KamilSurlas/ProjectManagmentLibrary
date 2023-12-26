#pragma once
#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
#include <chrono>
#include <time.h>

class FileHandler
{
private:
	static std::string* createFileName();
public:
	static void saveFile(const std::vector<std::string>& data);
};

