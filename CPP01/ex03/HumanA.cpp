#include "HumanA.hpp"

void HumanA::attack()
{
    std::cout << this->_name << " attacks with their " << _weapon.getType() << std::endl;
}

HumanA::HumanA(std::string name, Weapon& club): _name(name), _weapon(club) {
	
}
HumanA::~HumanA()
{
}
