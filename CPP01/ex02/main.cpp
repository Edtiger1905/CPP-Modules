/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epandele <epandele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 14:58:23 by epandele          #+#    #+#             */
/*   Updated: 2026/10/28 14:55:18 by epandele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(void)
{
    std::string brain = "HI THIS IS BRAIN";
    std::string* stringPTR;
    std::string& stringREF = brain;
    
    stringPTR = &brain;

    std::cout << "DEBUG ADDRESS: " << std::endl;
    std::cout << "Memory address of the string variable: " << &brain << std::endl;
    std::cout << "Memory address of string held by the pointer: " << stringPTR << std::endl;
    std::cout << "Memory address of string held by the reference: " << &stringREF << std::endl;
    
    std::cout << "DEBUG VALUE: " << std::endl;
    std::cout << "The value of the string is: " << brain << std::endl;
    std::cout << "The value pointed to by stringPTR is: " << *stringPTR << std::endl;
    std::cout << "The value pointed to by stringREF is: " << stringREF << std::endl; 
    
    return (0);
}