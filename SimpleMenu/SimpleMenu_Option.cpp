#include "SimpleMenu_Option.h"

std::string SimpleMenu_Option::GetName() const
{
    return this->name;
}

void SimpleMenu_Option::SetName(std::string argName) 
{
    this->name = argName;
}
