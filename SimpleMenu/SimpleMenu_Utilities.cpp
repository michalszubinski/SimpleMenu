#include "SimpleMenu_Utilities.h"

void SimpleMenu_Utilities::ClearScreen()
{
	for (int i = 0; i < 10; ++i) {
		std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	}
}

char SimpleMenu_Utilities::ReadKey()
{
	return _getch();
}
