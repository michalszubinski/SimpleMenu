#pragma once
#include "Libraries.h"
#include "SimpleMenu_Option.h"
#include "SimpleMenu_Utilities.h"

class SimpleMenu {
	std::string title;
	std::vector<SimpleMenu_Option> options;
	int activeOption;

public:

	SimpleMenu() {
		this->activeOption = 0;
		this->title = "My SimpleMenu";
	}

	void Run() {
		char x = 0;
		while (true) {
			Print();
			x = SimpleMenu_Utilities::ReadKey();
			SimpleMenu_Utilities::ClearScreen();
			if (x == 80) changeActiveOption('+');
			if (x == 72) changeActiveOption('-');
			if (x == 27) break;
			if (x == 13) std::cout << options[activeOption].GetName() << " - WAS SELECTED\n";
			std::cout << static_cast<int>(x) << std::endl;
		}
	}

	void Print() {
		std::cout << "-------------" << std::endl;
		std::cout << this->title << std::endl;
		std::cout << "-------------" << std::endl;

		int i = 0;
		for (const auto& option : this->options) {
			if (i == activeOption) std::cout << "[*]";
			else std::cout << "[ ]";

			std::cout << " | " << option.GetName() << std::endl;
			i++;
		}
	}

	void changeActiveOption(char dir) {
		switch (dir) {
		case '+': {
			++activeOption;
			if (activeOption >= options.size()) activeOption = 0;
		} break;

		case '-': {
			--activeOption;
			if (activeOption < 0) activeOption = options.size() - 1;
		} break;

		}
	}

	// TEST METHODS
	void TEST_AddRandomOptions(int argQuantity) {
		for (int i = 0; i < argQuantity; ++i) {
			options.push_back(SimpleMenu_Option("TEST"));
		}
	}

	void TEST_PrintAllOptionsNames() {
		for (const auto& option : this->options) {
			std::cout << option.GetName() << std::endl;
		}
	}
};