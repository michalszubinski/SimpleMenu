#pragma once
#include "Libraries.h"

class SimpleMenu_Option {
	std::string name;

public: 
	SimpleMenu_Option(std::string argName) : name(argName){ }

	std::string GetName() const;
	void SetName(std::string argName);
};