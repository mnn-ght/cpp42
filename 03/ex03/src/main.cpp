/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:54:30 by magahat           #+#    #+#             */
/*   Updated: 2024/12/11 15:51:12 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/DiamondTrap.hpp"

int main( void )
{
	/* ClapTrap	ClapTrap1("CL4P-TP");

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
	ScavTrap.attack("a really mean ennemy");

	FragTrap	FragTrap("FR4G-TP");
	FragTrap.highFivesGuys();
	FragTrap.highFivesGuys(); */

	DiamondTrap	DiaTrap("DI4-TP");
	DiaTrap.whoAmI();

	DiamondTrap	DiaTrap2(DiaTrap);
	DiaTrap2.whoAmI();

	DiamondTrap	DiaTrap3;
	DiaTrap3.whoAmI();
	return (0);
}