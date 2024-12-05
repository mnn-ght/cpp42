/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:20:29 by magahat           #+#    #+#             */
/*   Updated: 2024/12/05 11:57:47 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

/*
	CONSTRUCTORS
*/

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100, 50, 20)
{
	this->gatekeeper = false;
	std::cout << "\e[1;32mScavTrap " << name << " has been created !\e[0m" << std::endl;
}

ScavTrap::ScavTrap() : ClapTrap("NO_NAME", 100, 50, 20)
{
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

void ScavTrap::takeDamage(unsigned int amount)
{
	std::cout << "\e[2;37m---------------- START TAKE DAMAGE ACTION ----------------\e[0m" << std::endl;
	this->_HP -= amount;
	std::cout << "ScavTrap " << this->_name << " is attacked by a powerful ennemy, causing " << amount << " points of damage!" << std::endl;
	if (this->_HP <= 0)
		std::cout << "ScavTrap " << this->_name << " is destroyed!" << std::endl;
	else
		std::cout << "ScavTrap " << this->_name << " has now " << this->_HP << " points of health left."<< std::endl;
	std::cout << "-\e[2;37m----------------- END TAKE DAMAGE ACTION -----------------\e[0m" << std::endl;
	std::cout << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount)
{
	std::cout << "\e[2;37m---------------- START REPAIR ACTION ----------------\e[0m" << std::endl;
	if (this->_Energy <= 0)
		std::cout << "ScavTrap " << this->_name << " can't repairs itself. It has 0 energy points." << std::endl;
	else if (this->_HP <= 0)
		std::cout << "ScavTrap " << this->_name << " can't repairs itself. It was destroyed." << std::endl;
	else if (this->gatekeeper == true)
		std::cout << "ScavTrap " << this->_name << " can't repairs itself. It's in Gate keeper mode." << std::endl;
	else
	{
		this->_Energy--;
		if (this->_HP + amount > 100)
		{
			std::cout << "ScavTrap " << this->_name << " repairs itself with only " << amount - this->_HP << " points of health. It has reached max HP."<< std::endl;
			this->_HP = 100;
		}
		else
		{
			this->_HP += amount;
			std::cout << "ScavTrap " << this->_name << " successfully repairs itself with " << amount << " points of health left."<< std::endl;
		}
		std::cout << "ScavTrap " << this->_name << " has now " << this->_HP << " points of health left."<< std::endl;
	}
	std::cout << "\e[2;37m----------------- END REPAIR ACTION -----------------\e[0m" << std::endl;
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
