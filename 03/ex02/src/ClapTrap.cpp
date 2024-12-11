/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:32:55 by magahat           #+#    #+#             */
/*   Updated: 2024/12/11 15:26:47 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

/*
	CONSTRUCTORS
*/

ClapTrap::ClapTrap(std::string name) : _name(name), _HP(10), _Energy(10), _Damage(0)
{
	std::cout << "\e[1;32mClapTrap " << name << " has been created !\e[0m" << std::endl;
}

ClapTrap::ClapTrap(void) : _name("NO_NAME"), _HP(10), _Energy(10), _Damage(0)
{
	std::cout << "\e[1;32mDefault ClapTrap " << this->_name << " has been created !\e[0m" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &claptrap)
{
	*this = claptrap;
	std::cout << "\e[1;32mCopy ClapTrap " << this->_name << " has been created !\e[0m" << std::endl;
}

ClapTrap::ClapTrap(std::string name, int HP, int Energy, int Damage) : _name(name), _HP(HP), _Energy(Energy), _Damage(Damage)
{
	std::cout << "\e[1;32mAssembled ClapTrap " << name << " has been created !\e[0m" << std::endl;
}

/*
	DESTRUCTORS
*/

ClapTrap::~ClapTrap()
{
	std::cout << "\e[1;31mClapTrap " << this->_name << " has been destroyed !\e[0m" << std::endl;
}

/*
	OPERATORS OVERLOAD
*/

ClapTrap &ClapTrap::operator=(const ClapTrap &claptrap)
{
	if (this != &claptrap)
	{
		std::cout << "\e[1;32mClapTrap " << claptrap._name << " copied into " << this->_name << ".\e[0m"<< std::endl;
		this->_name = claptrap._name;
		this->_HP = claptrap._HP;
		this->_Energy = claptrap._Energy;
		this->_Damage = claptrap._Damage;
	}
	return (*this);
}

std::ostream	&operator<<(std::ostream& out, const ClapTrap &claptrap)
{
	out << claptrap.getName();
	return out;
}

/*
	MEMBER FUNCTIONS
*/

void ClapTrap::attack(const std::string& target)
{
	std::cout << "\e[2;37m---------------- START ATTACK ACTION ----------------\e[0m" << std::endl;
	if (this->_Energy == 0)
		std::cout << "ClapTrap " << this->_name << " can't attack. It has 0 energy points." << std::endl;
	else if (this->_HP <= 0)
		std::cout << "ClapTrap " << this->_name << " can't attack. It was destroyed." << std::endl;
	else
	{
		this->_Energy--;
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_Damage << " points of damage!" << std::endl;
	}
	std::cout << "\e[2;37m----------------- END ATTACK ACTION -----------------\e[0m" << std::endl;
	std::cout << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "\e[2;37m---------------- START TAKE DAMAGE ACTION ----------------\e[0m" << std::endl;
	this->_HP -= amount;
	std::cout << "ClapTrap " << this->_name << " is attacked (or it fell), causing " << amount << " points of damage!" << std::endl;
	if (this->_HP <= 0)
		std::cout << "ClapTrap " << this->_name << " is destroyed!" << std::endl;
	else
		std::cout << "ClapTrap " << this->_name << " has now " << this->_HP << " points of health left."<< std::endl;
	std::cout << "\e[2;37m----------------- END TAKE DAMAGE ACTION -----------------\e[0m" << std::endl;
	std::cout << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "\e[2;37m---------------- START REPAIR ACTION ----------------\e[0m" << std::endl;
	if (this->_Energy <= 0)
		std::cout << "ClapTrap " << this->_name << " can't repairs itself. It has 0 energy points." << std::endl;
	else if (this->_HP <= 0)
		std::cout << "ClapTrap " << this->_name << " can't repairs itself. It was destroyed." << std::endl;
	else
	{
		if (this->_HP + amount > 10)
		{
			std::cout << "ClapTrap " << this->_name << " repairs itself with only " << amount - this->_HP << " points of health. It has reached max HP."<< std::endl;
			this->_HP = 10;
		}
		else
		{
			this->_HP += amount;
			std::cout << "ClapTrap " << this->_name << " successfully repairs itself with " << amount << " points of health left."<< std::endl;
		}
		std::cout << "ClapTrap " << this->_name << " has now " << this->_HP << " points of health left."<< std::endl;
	}
	std::cout << "\e[2;37m----------------- END REPAIR ACTION -----------------\e[0m" << std::endl;
	std::cout << std::endl;
}

std::string	ClapTrap::getName(void) const
{
	return this->_name;
}
