/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epandele <epandele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 11:52:48 by epandele          #+#    #+#             */
/*   Updated: 2026/10/21 11:57:48 by epandele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <limits>

int main(void)
{
    PhoneBook phonebook;
    std::string str;
    
    while (true)
    {
        std::cout << "Enter a command (you can use ADD, SEARCH or EXIT):" << std::endl;
        std::getline(std::cin, str);
        if(std::cin.eof())
        {
            std::cout << "\nEOF detected. Exiting.\n";
            break; 
        }
        if(str == "ADD")
            phonebook.AddContact();
        
        if(str == "SEARCH")
            phonebook.SearchContact();
        
        if(str == "EXIT")
            break;
    }
    return (0);
}