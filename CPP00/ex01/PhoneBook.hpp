#ifndef PHONEBOOK.HPP
#define PHONEBOOK.HPP

#include <iomanip> //libreria usata per setw,
//che stronca dopo i 10 caratteri le stringhe della colonna
#include <iostream>
#include <string> //libreria per poter usare le stringhe
#include "Contact.hpp" // si importa Contact.hpp per prendere
//tutte le info sui contatti
#include <limits>
class PhoneBook
{
    private:
        Contact contacts[8];
        int index;
        int count;
        
    public:
        PhoneBook(); // costruttore di default
        ~PhoneBook(); // distruttore di default
        void AddContact();
        void SearchContact();
        void DisplayContact(int index);
};

#endif