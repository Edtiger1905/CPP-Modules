#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
    : _name(name), _HitPoints(10), _EnergyPoints(10), _AttackDamage(0)
{
    std::cout << "Default constructor called" << std::endl;
}
ClapTrap::ClapTrap(const ClapTrap &other)
{
    _name = other.getName();
    _HitPoints = other.getHit();
    _EnergyPoints = other.getEnergy();
    _AttackDamage = other.getAttack();
    std::cout << _name << "Copy constructor has been called." << std::endl;
}
ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    if(this != &other)
    {
        _name = other.getName();
        _HitPoints = other.getHit();
        _EnergyPoints = other.getEnergy();
        _AttackDamage = other.getAttack();
    }
    std::cout << _name << "Overload operator has been called." << std::endl;
    return (*this);
}
ClapTrap::~ClapTrap()
{
    std::cout << _name <<"Destructor called" << std::endl;
}
std::string ClapTrap::getName() const
{
    return (_name);
}
unsigned int ClapTrap::getHit() const
{
    return (_HitPoints);
}
unsigned int ClapTrap::getEnergy() const
{
    return (_EnergyPoints);
}
unsigned int ClapTrap::getAttack() const
{
    return (_AttackDamage);
}
void ClapTrap::setHit(int n)
{
    _HitPoints = n;
}
void ClapTrap::setEnergy(int n)
{
    _EnergyPoints = n;
}
void ClapTrap::attack(const std::string &target)
{
    if(_EnergyPoints > 0 && _HitPoints > 0)
    {
        std::cout << "ClapTrap " << _name << " attacks " << target << " causing " << _AttackDamage << " point of damage!" << std::endl;
        _EnergyPoints--;
        return ;
    }
    else
       std::cout << "ClapTrap " << _name << " can't attack." << std::endl;
}
void ClapTrap::takeDamage(unsigned int amount)
{
    if(amount >= _HitPoints)
        _HitPoints = 0;
    else
        _HitPoints -= amount;
     std::cout << "ClapTrap " << _name << " took " << amount << " points of damage." << std::endl;
}
void ClapTrap::beRepaired(unsigned int amount)
{
    if(_EnergyPoints > 0 && _HitPoints > 0)
    {
        _HitPoints += amount;
        _EnergyPoints--;
        std::cout << "ClapTrap " << _name << "repairs by " << amount << " hit points " << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << _name << " can't repair himself." << std::endl;
}