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
