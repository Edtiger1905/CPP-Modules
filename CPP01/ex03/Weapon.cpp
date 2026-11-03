/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epandele <epandele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 15:14:27 by epandele          #+#    #+#             */
/*   Updated: 2026/11/03 10:54:12 by epandele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon()
{
}
Weapon::Weapon(std::string type)
{
    this->setType(type);
}
Weapon::~Weapon()
{
}
std::string Weapon::getType()
{
    const std::string& typeref = type;
    return(typeref);
}
void Weapon::setType(std::string typeref)
{
    type = typeref;
}