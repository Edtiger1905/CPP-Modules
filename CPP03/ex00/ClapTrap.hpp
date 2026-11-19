#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <iostream>
#include <string>

class ClapTrap
{
private:
    std::string _name;
    int _HitPoints = 10;
    int _EnergyPoints = 10;
    int _AttackPoints = 0;
public:
    ClapTrap();
    ~ClapTrap();
    void attack(const std::string &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif