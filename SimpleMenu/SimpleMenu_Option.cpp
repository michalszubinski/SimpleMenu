#include "SimpleMenu_Option.h"

std::string SimpleMenu_Option::GetName() const
{
    return this->name;
}

void SimpleMenu_Option::SetName(std::string argName) 
{
    this->name = argName;
}

void SimpleMenu_Option::MoveAny(std::any argAny)
{
    anyObject.reset();

    anyObject = std::move(argAny);
}

std::optional<std::string> SimpleMenu_Option::getAnyType_OptionalString()
{
    try {
        std::optional<std::string> result{ anyObject.type().name() };
        return result;
    }
    catch(std::exception &ex){
        std::cout << ex.what() << std::endl;
        std::optional<std::string> empty;
        return empty;
    }
}

std::shared_ptr<std::any> SimpleMenu_Option::getPointerToAny()
{
    return std::make_shared<std::any>(anyObject);
}

