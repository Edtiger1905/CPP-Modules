#include "ScavTrap.hpp"
#include <iostream>

static void print_state(const ScavTrap& s)
{
    std::cout << "Name=" << s.getName()
              << " HP=" << s.getHit()
              << " EN=" << s.getEnergy()
              << " ATK=" << s.getAttack()
              << "\n";
}
int main(void)
{
    std::cout << "\n--- Basic Actions ---\n";
    ScavTrap a("Frau");
    print_state(a);

    a.guardGate();
    a.attack("Eduardo");
    a.takeDamage(10);
    a.beRepaired(5);
    print_state(a);

    std::cout << "\n--- Copy constructor ---\n";
    ScavTrap c(a);
    c.attack("copy-target");
    print_state(c);
    print_state(a);

    std::cout << "\n--- Copy assignment ---\n";
    ScavTrap b("B");
    b = a;
    b.attack("assigned-target");
    print_state(b);

    std::cout << "\n--- Dead check (HP=0) ---\n";
    ScavTrap d("D");
    d.takeDamage(200);
    d.attack("nope");
    d.beRepaired(10);
    print_state(d);

    return 0;
}