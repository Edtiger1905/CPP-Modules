/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epandele <epandele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 11:59:32 by epandele          #+#    #+#             */
/*   Updated: 2026/10/21 11:59:33 by epandele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>

Contact::Contact()
{
}
Contact::~Contact()
{
}
void Contact::setFirstName(std::string str)
{
    FirstName = str;
}
void Contact::setLastName(std::string str)
{
    LastName = str;
}
void Contact::setNickname(std::string str)
{
    Nickname = str;
}
void Contact::setPhoneNumber(std::string str)
{
    PhoneNumber = str;
}
void Contact::setDarkestSecret(std::string str)
{
    DarkestSecret = str;
}
std::string Contact::getFirstName()
{
    return(FirstName);
}
std::string Contact::getLastName()
{
    return(LastName);
}
std::string Contact::getNickname()
{
    return(Nickname);
}
std::string Contact::getPhoneNumber()
{
    return(PhoneNumber);
}
std::string Contact::getDarkestSecret()
{
    return(DarkestSecret);
}
