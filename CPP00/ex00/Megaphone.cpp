/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epandele <epandele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 12:00:37 by epandele          #+#    #+#             */
/*   Updated: 2026/10/21 12:00:38 by epandele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main(int ac, char** av)
{
    int i = 0;
    if(ac <= 2)
    {
        if(ac == 1)
            std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }
    int j = 1;
    while(av[j] != NULL && j <= ac)
    {
        i = 0;
        while (av[j][i] != '\0')
        {
            std::cout << (char)toupper(av[j][i]); 
            i++;
        }
        j++;
    }
    std::cout << std::endl; 

    return 0;
}