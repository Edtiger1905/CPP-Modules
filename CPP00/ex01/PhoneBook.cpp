#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    index = 0;
    count = 0;
}
PhoneBook::~PhoneBook()
{
}

static std::string trimContact(std::string str)
{
    if(str.length() > 10)
        str = str.substr(0, 9) + ".";
    return str;
}
void PhoneBook::SearchContact(void)
{
    int choice;

    if(count == 0)
    {
        std::cout << "Nothing to see there." << std::endl;
        return ;
    }
    std::cout << "|"
                << std::setw(10) << "Index" << "|"
                << std::setw(10) << "First Name" << "|"
                << std::setw(10) << "Last Name" << "|"
                << std::setw(10) << "Nickname" << "|" << std::endl;
    
    for(int i = 0; i < count; i++)
    {
        
    }
}