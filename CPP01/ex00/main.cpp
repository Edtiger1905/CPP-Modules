/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epandele <epandele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 14:11:26 by epandele          #+#    #+#             */
/*   Updated: 2026/11/09 14:11:43 by epandele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Zombie.hpp"

void randomChump(std::string name);

static void title(const std::string &t)
{
	std::cout << "\n===== " << t << " =====" << std::endl;
}

int main(void)
{
	Zombie factory("Factory");

	title("TEST 1: zombie sullo stack (distrutto a fine scope)");
	{
		Zombie stackZombie("Stack");
		stackZombie.announce();
		std::cout << "-> sto per uscire dallo scope" << std::endl;
	}
	std::cout << "-> scope finito: 'Stack' deve essere gia' stato stampato dal distruttore" << std::endl;

	title("TEST 2: newZombie (heap, sopravvive alla funzione)");
	Zombie *heapZombie = factory.newZombie("Heap");
	if (!heapZombie)
	{
		std::cerr << "newZombie ha restituito NULL" << std::endl;
		return 1;
	}
	heapZombie->announce();
	std::cout << "-> Heap e' ancora vivo, lo elimino con delete" << std::endl;
	delete heapZombie;

	title("TEST 3: randomChump (creato e distrutto dentro la funzione)");
	randomChump("Chump");
	std::cout << "-> randomChump e' tornata: 'Chump' deve essere gia' stato distrutto" << std::endl;

	title("TEST 4: piu' zombie sull'heap, distruzione in ordine diverso");
	Zombie *a = factory.newZombie("Alpha");
	Zombie *b = factory.newZombie("Beta");
	Zombie *c = factory.newZombie("Gamma");
	a->announce();
	b->announce();
	c->announce();
	delete b;
	delete a;
	delete c;

	title("TEST 5: nomi particolari (vuoto, spazi, lungo)");
	randomChump("");
	randomChump("Mario Rossi");
	randomChump("UnNomeMoltoMoltoMoltoMoltoMoltoMoltoMoltoMoltoLungo");
	Zombie *empty = factory.newZombie("");
	empty->announce();
	delete empty;

	title("TEST 6: stack e heap insieme (ordine dei distruttori)");
	{
		Zombie s1("S1");
		Zombie *h1 = factory.newZombie("H1");
		Zombie s2("S2");
		s1.announce();
		h1->announce();
		s2.announce();
		delete h1;
		std::cout << "-> H1 eliminato, ora escono S2 e S1 (ordine inverso)" << std::endl;
	}

	title("TEST 7: tanti zombie in loop (controllo leak)");
	for (int i = 0; i < 1000; i++)
	{
		Zombie *z = factory.newZombie("Loop");
		delete z;
	}
	std::cout << "1000 zombie creati e distrutti" << std::endl;

	title("FINE: tra poco esce 'Factory'. Controlla con valgrind i leak");
	return 0;
}