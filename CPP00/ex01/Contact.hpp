#ifndef CONTACT.HPP
#define CONTACT.HPP

#include <string>

class Contact
{
    private:
        std::string FirstName;
        std::string LastName;
        std::string Nickname;
        std::string PhoneNumber;
        std::string DarkestSecret;
    
    public:
        Contact();
        ~Contact();
        void Contact::setFirstName(std::string str);
        void Contact::setLastName(std::string str);
        void Contact::setNickname(std::string str);
        void Contact::setPhoneNumber(std::string str);
        void Contact::setDarkestSecret(std::string str);
        std::string getFirstName();
        std::string getLastName();
        std::string getNickname();
        std::string getPhoneNumber();
        std:: string getDarkestSecret();

};


#endif