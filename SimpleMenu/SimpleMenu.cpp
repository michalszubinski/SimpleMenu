#include "SimpleMenu.h"
#include "SimpleMenu_Functions.h"


SimpleMenu::SimpleMenu() {
	this->activeOption = 0;
	this->title = "My SimpleMenu";
}

void SimpleMenu::Run() {
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

void SimpleMenu::Print() {
	std::cout << "-------------" << std::endl;
	std::cout << this->title << std::endl;
	std::cout << "-------------" << std::endl;

	int i = 0;
	for (auto& option : this->options) {
		if (i == activeOption) std::cout << "[*]";
		else std::cout << "[ ]";

		std::cout << " | " << option.GetName() << "     " << option.getAnyType_OptionalString().value_or("Error while returning option optional any type") << std::endl;
		i++;
	}
}

void SimpleMenu::changeActiveOption(char dir) {
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

std::optional<std::shared_ptr<SimpleMenu_Option> > SimpleMenu::getOptionalOptionPointer(int id)
{
	try {
		std::optional<std::shared_ptr<SimpleMenu_Option> > o{ std::make_shared<SimpleMenu_Option>(options[id]) };
		return o;
	}
	catch(std::exception& ex){
		std::cout << ex.what() << std::endl;
		std::optional<std::shared_ptr<SimpleMenu_Option> > o;
		return o;
	}
}

// METHODS FOR TESTING

void SimpleMenu::TEST_AddRandomOptions(int argQuantity) {
	for (int i = 0; i < argQuantity; ++i) {
		options.push_back(SimpleMenu_Option("TEST"));
	}
}

void SimpleMenu::TEST_AddRandomOptions_AnyTest(int argQuantity) {
	for (int i = 0; i < argQuantity; ++i) {
		if (i == 0) {
			bool test{ true };
			std::any anyBool{ test };
			options.push_back(SimpleMenu_Option("TEST", anyBool));
		}
		else if (i == 1) {
			auto title_pointer = std::make_shared<std::string>(title);
			std::any anyPointer{ std::move(title_pointer) };
			options.push_back(SimpleMenu_Option("TEST", anyPointer));
		}
		else if (i == 2) {
			/**/
			std::function<void()> functionObject(std::bind(&SimpleMenu::TEST_PrintSampleText, this));
			std::any anyPointer{ functionObject };
			options.push_back(SimpleMenu_Option("TEST", anyPointer));

			// CALL THE FUNCTION V1
			/*

			auto pointer = options[i].getPointerToAny(); // get smart pointer to any
			//std::any_cast< std::function<void()> >( pointer.get() ); //pointer.get();
			auto anyy = *pointer.get(); // get any
			auto functionObj2 = std::any_cast<std::function<void()>>( anyy ); // get function object
			functionObj2();
			//SimpleMenu_Functions::Test();*/

			// CALL THE FUNCTION V2
			SimpleMenu_Functions::RunOptionsFunction<void, void()>(options[i]);

		}
		else {
			options.push_back(SimpleMenu_Option("TEST"));
		}
	}
}

void SimpleMenu::TEST_PrintAllOptionsNames() {
	for (const auto& option : this->options) {
		std::cout << option.GetName() << std::endl;
	}
}

void SimpleMenu::TEST_PrintSampleText()
{
	std::cout << "Sample text\n";
}
