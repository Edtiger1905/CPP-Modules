#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    _name = name, _HitPoints = 100, _EnergyPoints = 100, _AttackDamage = 30;
    std::cout << "FragTrap " << _name << " constructor has been called" << std::endl;
}
FragTrap::FragTrap(FragTrap &other) : ClapTrap(other)
{
    std::cout << "FragTrap " << _name << " copy constructor has been called" << std::endl;
}
FragTrap& FragTrap::operator=(const FragTrap& other)
{
    if(this != &other)
    {
        ClapTrap::operator=(other);
        std::cout << "FragTrap " << _name << " operator= has been called" << std::endl;
    }
    return *this;
}
FragTrap::~FragTrap()
{
    std::cout << " FragTrap " << _name << " destructor has been called" << std::endl;
}
void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap highfives some guys. Yeah." << std::endl;
}
