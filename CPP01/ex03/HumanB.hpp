#ifndef HUMANB_HPP
# define HUMANB_HPP
#include "Weapon.hpp"

class HumanB
{
    private:
        std::string _name;
        Weapon* _weapon;
    public:
        HumanB();
        HumanB(std::string name);
        void setWeapon(Weapon& club);
        ~HumanB();
        void attack();
};
#endif