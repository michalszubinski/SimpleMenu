#pragma once
#include "SimpleMenu_Libraries.h"
#include "SimpleMenu_Option.h"
#include "SimpleMenu_Utilities.h"

class SimpleMenu {
	std::string title;
	std::vector<SimpleMenu_Option> options;
	int activeOption;

public:

	SimpleMenu();

	void Run();
	void Print();
	void changeActiveOption(char dir);

	// METHODS FOR TESTING
	void TEST_AddRandomOptions(int argQuantity);
	void TEST_PrintAllOptionsNames();
};