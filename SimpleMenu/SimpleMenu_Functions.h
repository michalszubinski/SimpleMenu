#pragma once

#include "SimpleMenu_Libraries.h"
#include "SimpleMenu.h"

//template<typename func_return>
namespace SimpleMenu_Functions {

	template<typename func_return, typename func_call>
	func_return RunOptionsFunction(SimpleMenu& menuRef, int id) {
		try {
			auto optionalPointerToAny = menuRef.getOptionalOptionPointer(id);
			auto pointerToOption = optionalPointerToAny.value();
			auto menuOption = *pointerToOption.get(); // get option
			auto pointerToAny = menuOption.getPointerToAny();
			auto anyObject = *pointerToAny.get(); // get any
			auto functionObj = std::any_cast<std::function< func_call >>(anyObject); // get function object
			return functionObj();
		}
		catch (std::exception& ex) {
			std::cout << ex.what() << std::endl;
			return;
		}
	}

	template<typename func_return, typename func_call>
	func_return RunOptionsFunction(SimpleMenu_Option optionRef) {
		try {
			auto pointerToAny = optionRef.getPointerToAny();
			auto anyObject = *pointerToAny.get(); // get any
			auto functionObj = std::any_cast<std::function< func_call >>(anyObject); // get function object
			return functionObj();
		}
		catch (std::exception& ex) {
			std::cout << ex.what() << std::endl;
			return;
		}
	}

	void Test() {}

	template<typename T>
	void Test2() {}
}