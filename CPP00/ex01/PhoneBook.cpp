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
        std::cout << std::right << "|";
        std::cout << std::setw(10) << i + 1 << "|";
        std::cout << std::setw(10) << trimContact(contacts[i].getFirstName()) << "|";
        std::cout << std::setw(10) << trimContact(contacts[i].getLastName()) << "|";
        std::cout << std::setw(10) << trimContact(contacts[i].getNickname()) << "|";
        std::cout << std::endl;
    }
    std::cout << "Enter contact index:";
    std::cin >> index;
    if(!std::cin)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid index.\n";
        return ;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if((index > 0 && index < 9))
        DisplayContact(index - 1);
    else
        return ;
}
static bool is_valid(const std::string& s,int digits_flag)
{
    bool all_spaces = true;
    for(size_t i = 0; i < s.length(); i++)
    {
        if(!isspace(static_cast<unsigned char>(s[i])))
        {
            all_spaces = false;
            break;
        }
    }
    if(s.empty() || all_spaces)
        return false;
    if(digits_flag == 1)
    {
        for (size_t i = 0; i < s.length(); i++)
        {
            if(!isdigit(static_cast<unsigned char>(s[i])))
                return false;
        }
    }
    return true;
}
