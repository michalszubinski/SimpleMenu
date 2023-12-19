#pragma once
#include "SimpleMenu_Libraries.h"

class SimpleMenu_Option {
	std::string name;
	std::any anyObject;

public: 
	SimpleMenu_Option(std::string argName) : name(argName){ }

	std::string GetName() const;
	void SetName(std::string argName);

	std::optional<std::string> getAnyType_OptionalString();
};