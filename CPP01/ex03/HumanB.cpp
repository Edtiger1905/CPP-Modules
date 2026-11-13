/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epandele <epandele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 14:07:50 by epandele          #+#    #+#             */
/*   Updated: 2026/11/09 14:07:51 by epandele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

void HumanB::attack()
{
    std::cout << this->_name << " attacks with their " << _weapon->getType() << std::endl;
}
HumanB::HumanB()
{
}
HumanB::HumanB(std::string name)
{
    this->_name = name;
}
void HumanB::setWeapon(Weapon& club)
{
    this->_weapon = &club;
}

HumanB::~HumanB()
{
}
