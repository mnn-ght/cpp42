/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:54:30 by magahat           #+#    #+#             */
/*   Updated: 2024/12/11 15:18:18 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

int main( void )
{
	ClapTrap ClapTrap1("CL4P-TP---1");

	ClapTrap1.attack("an insect that did nothing");
	ClapTrap1.takeDamage(5);
	ClapTrap1.beRepaired(2);
	
	ClapTrap1.takeDamage(7);
	ClapTrap1.beRepaired(2);

	ClapTrap ClapTrap2("CL4P-TP---2");
	std::cout << ClapTrap2 << " is wandering in the field." << std::endl;
	ClapTrap2.attack("an insect that did nothing");
	ClapTrap2.attack("an insect that did nothing");
	ClapTrap2.attack("an insect that did nothing");
	ClapTrap2.attack("an insect that did nothing");
	ClapTrap2.attack("an insect that did nothing");
	ClapTrap2.attack("an insect that tickled it");
	ClapTrap2.attack("an insect that did nothing");
	ClapTrap2.attack("an insect that did nothing");
	ClapTrap2.attack("an insect that did nothing");
	ClapTrap2.attack("an insect that did nothing");
	ClapTrap2.attack("an insect that did nothing");
	ClapTrap2.beRepaired(2);
	
	ClapTrap clap;
	clap.attack("an insect");

	return (0);
}