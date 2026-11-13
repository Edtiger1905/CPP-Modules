/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epandele <epandele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 14:12:00 by epandele          #+#    #+#             */
/*   Updated: 2026/11/09 14:12:01 by epandele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
#include <string>
#include <iostream>

class Zombie
{
    private:
        std::string _name;

    public:
        void announce (void);
        Zombie();
        Zombie(std::string name);
        Zombie* newZombie(std::string name);
        ~Zombie();
};


#endif