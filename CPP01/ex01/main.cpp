/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epandele <epandele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 14:53:25 by epandele          #+#    #+#             */
/*   Updated: 2026/10/26 14:53:26 by epandele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Zombie.hpp"

// zombieHorde non e' dichiarata in Zombie.hpp: la dichiaro qui.
Zombie* zombieHorde(int N, std::string name);

static void title(const std::string &t)
{
	std::cout << "\n===== " << t << " =====" << std::endl;
}

static void testHorde(int N, const std::string &name)
{
	Zombie *horde = zombieHorde(N, name);

	if (N > 0 && !horde)
	{
		std::cerr << "zombieHorde ha restituito NULL" << std::endl;
		return;
	}
	// announce() su ogni zombie e stampa degli indirizzi:
	// se l'allocazione e' unica, la distanza tra indirizzi e' sizeof(Zombie)
	for (int i = 0; i < N; i++)
	{
		std::cout << "[" << i << "] " << &horde[i] << " -> ";
		horde[i].announce();
	}
	std::cout << "sizeof(Zombie) = " << sizeof(Zombie) << std::endl;
	std::cout << "-> delete[] della horde da " << N << " (devo vedere " << N
		<< " distruttori)" << std::endl;
	delete[] horde;
}

int main(void)
{
	title("TEST 1: horde da 5");
	testHorde(5, "Walker");

	title("TEST 2: horde da 1");
	testHorde(1, "Solo");

	title("TEST 3: horde da 0");
	testHorde(0, "Nessuno");

	title("TEST 4: due horde insieme con nomi diversi");
	Zombie *h1 = zombieHorde(3, "Alpha");
	Zombie *h2 = zombieHorde(2, "Beta");
	for (int i = 0; i < 3; i++)
		h1[i].announce();
	for (int i = 0; i < 2; i++)
		h2[i].announce();
	delete[] h1;
	delete[] h2;

	title("TEST 5: horde grande (controllo leak)");
	Zombie *big = zombieHorde(1000, "Big");
	big[0].announce();
	big[999].announce();
	delete[] big;

	title("FINE: controlla con valgrind che non ci siano leak");
	return 0;
}