/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:20:29 by magahat           #+#    #+#             */
/*   Updated: 2024/12/05 12:46:20 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

/*
	CONSTRUCTORS
*/

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->_HP = 100;
	this->_Energy = 50;
	this->_Damage = 20;
	this->gatekeeper = false;
	std::cout << "\e[1;32mScavTrap " << name << " has been created !\e[0m" << std::endl;
}

ScavTrap::ScavTrap() : ClapTrap("NO_NAME")
{
	this->_HP = 100;
	this->_Energy = 50;
	this->_Damage = 20;
	this->gatekeeper = false;
	std::cout << "\e[1;32mScavTrap NO_NAME has been created !\e[0m" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &scavtrap) : ClapTrap(scavtrap._name, scavtrap._HP, scavtrap._Energy, scavtrap._Damage)
{
	this->gatekeeper = scavtrap.gatekeeper;
	std::cout << "\e[1;32mCopy ScavTrap " << this->_name << " has been created !\e[0m" << std::endl;
}

/*
	DESTRUCTORS
*/

ScavTrap::~ScavTrap()
{
	std::cout << "\e[1;31mScavTrap " << this->_name << " has been destroyed !\e[0m" << std::endl;
}

/*
	OPERATORS OVERLOAD
*/

ScavTrap	&ScavTrap::operator=(const ScavTrap &scavtrap)
{
	if (this != &scavtrap)
	{
		std::cout << "\e[1;32mScavTrap " << scavtrap._name << " copied into " << this->_name << std::endl;
		this->_name = scavtrap._name;
		this->_HP = scavtrap._HP;
		this->_Energy = scavtrap._Energy;
		this->_Damage = scavtrap._Damage;
		this->gatekeeper = scavtrap.gatekeeper;
	}
	return (*this);
}

/*
	MEMBER FUNCTIONS
*/

void ScavTrap::attack(const std::string& target)
{
	std::cout << "\e[2;37m---------------- START ATTACK ACTION ----------------\e[0m" << std::endl;
	if (this->_Energy == 0)
		std::cout << "ScavTrap " << this->_name << " can't attack. It has 0 energy points." << std::endl;
	else if (this->_HP <= 0)
		std::cout << "ScavTrap " << this->_name << " can't attack. It was destroyed." << std::endl;
	else if (this->gatekeeper == true)
		std::cout << "ScavTrap " << this->_name << " can't attack " << target << ". It's in Gate keeper mode." << std::endl;
	else
	{
		this->_Energy--;
		std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_Damage << " points of damage!" << std::endl;
	}
	std::cout << "\e[2;37m----------------- END ATTACK ACTION -----------------\e[0m" << std::endl;
	std::cout << std::endl;
}

void ScavTrap::guardGate( void )
{
	std::cout << "\e[2;37m---------------- START GATEKEEPER ACTION ----------------\e[0m" << std::endl;
	if (this->gatekeeper == false)
	{
		std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode"<< std::endl;
		this->gatekeeper = true;
	}
	else
		std::cout << "ScavTrap " << this->_name << " is already in Gate keeper mode"<< std::endl;
	std::cout << "\e[2;37m----------------- END GATEKEEPER ACTION -----------------\e[0m" << std::endl;
	std::cout << std::endl;
}

std::string	ScavTrap::getName(void)
{
	return this->_name;
}

int	ScavTrap::getHP(void)
{
	return 100;
}

int	ScavTrap::getEnergy(void)
{
	return 50;
}

int	ScavTrap::getDamage(void)
{
	return 20;
}
