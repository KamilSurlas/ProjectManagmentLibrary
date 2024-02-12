#pragma once
// abstract
#include <string>
#include "TaskProject.h"
using namespace std;
class Manager
{
protected:
	virtual void editName(TaskProject& target, string name) = 0;
	virtual void editDescription(TaskProject& target, string desc) =0;
public:
	virtual ~Manager() {}
};

