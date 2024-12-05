/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:20:29 by magahat           #+#    #+#             */
/*   Updated: 2024/12/05 12:46:20 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/DiamondTrap.hpp"

/*
	CONSTRUCTORS
*/

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), ScavTrap(name), FragTrap(name)
{
	this->_name = name;
	this->ClapTrap::_name = this->_name + "_clap_name";
	this->_HP = FragTrap::getHP();
	this->_Energy = ScavTrap::getEnergy();
	this->_Damage = FragTrap::getDamage();
	std::cout << "\e[1;32mDiamondTrap " << name << " has been created !\e[0m" << std::endl;
}

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap()
{
	this->ClapTrap::_name = this->_name + "_clap_name";
	this->_HP = FragTrap::getHP();
	this->_Energy = ScavTrap::getEnergy();
	this->_Damage = FragTrap::getDamage();
	std::cout << "\e[1;32mDiamondTrap NO_NAME has been created !\e[0m" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &DiamondTrap) : ClapTrap(DiamondTrap._name), ScavTrap(DiamondTrap._name), FragTrap(DiamondTrap._name)
{
	*this = DiamondTrap;
	std::cout << "\e[1;32mCopy DiamondTrap " << this->_name << " has been created !\e[0m" << std::endl;
}

/*
	DESTRUCTORS
*/

DiamondTrap::~DiamondTrap()
{
	std::cout << "\e[1;31mDiamondTrap " << this->_name << " has been destroyed !\e[0m" << std::endl;
}

/*
	OPERATORS OVERLOAD
*/

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &DiamondTrap)
{
	if (this != &DiamondTrap)
	{
		std::cout << "\e[1;32mDiamondTrap " << DiamondTrap._name << " copied into " << this->_name << std::endl;
		this->_name = DiamondTrap._name;
		this->ClapTrap::_name = DiamondTrap.ClapTrap::_name;
		this->_HP = DiamondTrap._HP;
		this->_Energy = DiamondTrap._Energy;
		this->_Damage = DiamondTrap._Damage;
	}
	return (*this);
}

/*
	MEMBER FUNCTIONS
*/

void DiamondTrap::attack(const std::string& target)
{
	this->ScavTrap::attack(target);
}

void DiamondTrap::whoAmI( void )
{
	std::cout << "I am " << this->_name << ", and my Claptrap name is " << this->ClapTrap::_name << std::endl;
}