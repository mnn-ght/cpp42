/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:54:30 by magahat           #+#    #+#             */
/*   Updated: 2024/12/11 15:07:44 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"
#include "../includes/FragTrap.hpp"

int main( void )
{
/* 	ClapTrap	ClapTrap1("CL4P-TP");

	ClapTrap1.attack("an insect that did nothing");
	ClapTrap1.takeDamage(5);
	ClapTrap1.beRepaired(2);
	
	ClapTrap1.takeDamage(7);
	ClapTrap1.beRepaired(2);

	ScavTrap	ScavTrap("SC4V-TP");
	ScavTrap.attack("a really mean ennemy");
	ScavTrap.takeDamage(50);
	ScavTrap.beRepaired(62);
	ScavTrap.guardGate();
	ScavTrap.attack("a really mean ennemy"); */

	FragTrap	f1("FR4G-TP");
	FragTrap	f2;
	FragTrap	f3(f1);
	
	f2.highFivesGuys();

	return (0);
}