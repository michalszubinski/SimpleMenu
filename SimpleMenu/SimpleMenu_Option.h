#pragma once
#include "SimpleMenu_Libraries.h"

class SimpleMenu_Option {
	std::string name;
	std::any anyObject;

public: 
	SimpleMenu_Option(std::string argName) : name(argName){ }
	SimpleMenu_Option(std::string argName, std::any argAny) : name(argName), anyObject(std::move(argAny)){ }

	std::string GetName() const;
	void SetName(std::string argName);

	void MoveAny(std::any argAny);

	std::optional<std::string> getAnyType_OptionalString();
};