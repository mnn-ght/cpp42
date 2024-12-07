/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:54:30 by magahat           #+#    #+#             */
/*   Updated: 2024/12/07 14:43:58 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

/* Zombie	randomChump2(std::string name) //TEST Pour montrer diff stack et heap
{
	Zombie	randomChump(name);

	randomChump.announce();
	return (randomChump);
} */

int	main(void)
{
	Zombie	OriginalZombie("Didier");
	OriginalZombie.announce();

	Zombie	*new_zombie;
	new_zombie = newZombie("Pascal");
	(*new_zombie).announce();
	delete new_zombie;

	randomChump("Yves");

	// std::cout << "debut test" << std::endl;
	// randomChump2("Yves2");
	// std::cout << "fin test" << std::endl << std::endl;

	return (0);
}
