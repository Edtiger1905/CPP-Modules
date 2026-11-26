#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP
#include <iostream>
#include <string>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

class FragTrap : public ClapTrap
{
public:
    FragTrap(std::string name);
    FragTrap(FragTrap &other);
    FragTrap &operator=(const FragTrap &other);
    ~FragTrap();
    
    void highFivesGuys(void);
};

#endif