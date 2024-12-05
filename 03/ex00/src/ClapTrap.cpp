/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:32:55 by magahat           #+#    #+#             */
/*   Updated: 2024/12/05 09:50:38 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

/*
	CONSTRUCTORS
*/

ClapTrap::ClapTrap(std::string name) : _name(name), _HP(10), _Energy(10), _Damage(0)
{
	std::cout << "ClapTrap " << name << " has been created !" << std::endl;
}

ClapTrap::ClapTrap(void) : _name("NO_NAME"), _HP(10), _Energy(10), _Damage(0)
{
	std::cout << "Default ClapTrap " << this->_name << " has been created !" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &claptrap)
{
	std::cout << "Copy ClapTrap " << this->_name << " has been created !" << std::endl;
	*this = claptrap;
}

ClapTrap::ClapTrap(std::string name, int HP, int Energy, int Damage) : _name(name), _HP(HP), _Energy(Energy), _Damage(Damage)
{
	std::cout << "Assembled ClapTrap " << name << " has been created !" << std::endl;
}

/*
	DESTRUCTORS
*/

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->_name << " has been destroyed !" << std::endl;
}

/*
	OPERATORS OVERLOAD
*/

ClapTrap &ClapTrap::operator=(const ClapTrap &claptrap)
{
	this->~ClapTrap();
	new(this) ClapTrap(claptrap._name, claptrap._HP, claptrap._Energy, claptrap._Damage);
	return (*this);
}

/*
	MEMBER FUNCTIONS
*/

void ClapTrap::attack(const std::string& target)
{
	if (this->_Energy == 0)
		std::cout << "ClapTrap " << this->_name << " can't attack. It has 0 energy points." << std::endl;
	else if (this->_HP <= 0)
		std::cout << "ClapTrap " << this->_name << " can't attack. It was destroyed." << std::endl;
	else
	{
		this->_Energy--;
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_Damage << " points of damage!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	this->_HP -= amount;
	std::cout << "ClapTrap " << this->_name << " is attacked (or it fell), causing " << amount << " points of damage!" << std::endl;
	if (this->_HP <= 0)
		std::cout << "ClapTrap " << this->_name << " is destroyed!" << std::endl;
	else
		std::cout << "ClapTrap " << this->_name << " has now " << this->_HP << " points of health left."<< std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_Energy <= 0)
		std::cout << "ClapTrap " << this->_name << " can't repairs itself. It has 0 energy points." << std::endl;
	else if (this->_HP <= 0)
		std::cout << "ClapTrap " << this->_name << " can't repairs itself. It was destroyed." << std::endl;
	else
	{
		this->_Energy--;
		this->_HP += amount;
		std::cout << "ClapTrap " << this->_name << " successfully repairs itself with " << amount << " points of health left."<< std::endl;
		std::cout << "ClapTrap " << this->_name << " has now " << this->_HP << " points of health left."<< std::endl;
	}
}
