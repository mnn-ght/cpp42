/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:54:30 by magahat           #+#    #+#             */
/*   Updated: 2024/12/11 15:24:30 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

int main( void )
{
/* 	ClapTrap	ClapTrap1("CL4P-TP---1");

	ClapTrap1.attack("an insect that did nothing");
	ClapTrap1.takeDamage(5);
	ClapTrap1.beRepaired(2);
	
	ClapTrap1.takeDamage(7);
	ClapTrap1.beRepaired(2); */
	{
		ScavTrap	Scav("SC4V-TP---1");
		ScavTrap	Scav2(Scav);
		
		Scav.attack("a really mean ennemy");
		Scav.guardGate();
		Scav.attack("a really mean ennemy");
		std::cout << Scav << " is inspecting the field." << std::endl;
		
		Scav2.attack("a really mean ennemy");
		Scav2.guardGate();
		Scav2.attack("a really mean ennemy");
		std::cout << Scav2 << " is inspecting the field." << std::endl;
	}
	{
		ScavTrap	Scav;
		
		Scav.attack("a really mean ennemy");
		Scav.guardGate();
		Scav.attack("a really mean ennemy");
		std::cout << Scav << " is inspecting the field." << std::endl;
	}

	return (0);
}