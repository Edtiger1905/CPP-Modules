/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epandele <epandele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 11:35:34 by epandele          #+#    #+#             */
/*   Updated: 2026/11/06 11:35:35 by epandele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <string>

int main(int ac, char **av)
{
    std::string line;
    std::string s1;
    std::string s2;
    std::string filename;

    if(ac != 4)
    {
        std::cout << "Usage: <filename> <s1> <s2>" << std::endl;
        return 1;
    }
    filename = av[1];
    s1 = av[2];
    s2 = av[3];
    if(s1.length() == 0)
    {
        std::cout << "s1 should contain something";
        return 1;
    }
    std::ifstream file(filename.c_str());
    if(!file.is_open())
    {
        std::cout << "File could not be opened" << std::endl;
        return 1;
    }
    std::string outname = filename + ".replace";
    std::ofstream new_file(outname.c_str());
    if(!new_file.is_open())
    {
        std::cout << "Error: new file not created" << std::endl;
        return 1;
    }
    while(std::getline(file, line))
    {
        std::string result;
        std::size_t pos = 0;
        std::size_t found = 0;
        while(1)
        {
            found = line.find(s1, found);
            if(found == std::string::npos)
            {
                result += line.substr(pos);
                break;
            }
            result += line.substr(pos, found - pos);
            result += s2;
            pos = found + s1.length();
            found += s1.length();
        }
        new_file << result << std::endl;
    }
    file.close();
    new_file.close();
    return 0;
}