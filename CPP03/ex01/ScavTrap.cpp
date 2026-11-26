#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    _name = name, _HitPoints = 100, _EnergyPoints = 50, _AttackDamage = 20;
    std::cout << "ScavTrap " << _name << " constructor has been called" << std::endl;
}
ScavTrap::ScavTrap(ScavTrap &other) : ClapTrap(other)
{
    std::cout << "ScavTrap " << _name << " copy constructor has been called" << std::endl;
}
ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    if(this != &other)
    {
        ClapTrap::operator=(other);
        std::cout << "ScavTrap " << _name << " operator= has been called" << std::endl;
    }
    return *this;
}
ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << _name << " destructor called" << std::endl;
}
void ScavTrap::guardGate(void)
{
    std::cout << "ScavTrap " << _name << " is now in Gate keeper mode" << std::endl;
}
void ScavTrap::attack(const std::string &target)
{
    if(_EnergyPoints > 0 && _HitPoints > 0)
    {
        std::cout << "ScavTrap " << _name << " attacks " << target << " causing " << _AttackDamage << " points of damage!" << std::endl;
        _EnergyPoints--;
        return ;
    }
    else
        std::cout << "ScavTrap " << _name << " can't attack." << std::endl; 
}