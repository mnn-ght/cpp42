/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:20:29 by magahat           #+#    #+#             */
/*   Updated: 2024/12/05 12:29:41 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FragTrap.hpp"

/*
	CONSTRUCTORS
*/

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_HP = 100;
	this->_Energy = 100;
	this->_Damage = 30;
	std::cout << "\e[1;32mFragTrap " << name << " has been created !\e[0m" << std::endl;
}

FragTrap::FragTrap() : ClapTrap("NO_NAME")
{
	this->_HP = 100;
	this->_Energy = 100;
	this->_Damage = 30;
	std::cout << "\e[1;32mFragTrap NO_NAME has been created !\e[0m" << std::endl;
}

FragTrap::FragTrap(const FragTrap &FragTrap) : ClapTrap(FragTrap._name, FragTrap._HP, FragTrap._Energy, FragTrap._Damage)
{
	std::cout << "\e[1;32mCopy FragTrap " << this->_name << " has been created !\e[0m" << std::endl;
}

/*
	DESTRUCTORS
*/

FragTrap::~FragTrap()
{
	std::cout << "\e[1;31mFragTrap " << this->_name << " has been destroyed !\e[0m" << std::endl;
}

/*
	OPERATORS OVERLOAD
*/

FragTrap	&FragTrap::operator=(const FragTrap &FragTrap)
{
	if (this != &FragTrap)
	{
		std::cout << "\e[1;32mFragTrap " << FragTrap._name << " copied into " << this->_name << std::endl;
		this->_name = FragTrap._name;
		this->_HP = FragTrap._HP;
		this->_Energy = FragTrap._Energy;
		this->_Damage = FragTrap._Damage;
	}
	return (*this);
}

/*
	MEMBER FUNCTIONS
*/

void FragTrap::attack(const std::string& target)
{
	std::cout << "\e[2;37m---------------- START ATTACK ACTION ----------------\e[0m" << std::endl;
	if (this->_Energy == 0)
		std::cout << "FragTrap " << this->_name << " can't attack. It has 0 energy points." << std::endl;
	else if (this->_HP <= 0)
		std::cout << "FragTrap " << this->_name << " can't attack. It was destroyed." << std::endl;
	else
	{
		this->_Energy--;
		std::cout << "FragTrap " << this->_name << " attacks " << target << ", causing " << this->_Damage << " points of damage!" << std::endl;
	}
	std::cout << "\e[2;37m----------------- END ATTACK ACTION -----------------\e[0m" << std::endl;
	std::cout << std::endl;
}

void FragTrap::takeDamage(unsigned int amount)
{
	std::cout << "\e[2;37m---------------- START TAKE DAMAGE ACTION ----------------\e[0m" << std::endl;
	this->_HP -= amount;
	std::cout << "FragTrap " << this->_name << " is attacked by a powerful ennemy, causing " << amount << " points of damage!" << std::endl;
	if (this->_HP <= 0)
		std::cout << "FragTrap " << this->_name << " is destroyed!" << std::endl;
	else
		std::cout << "FragTrap " << this->_name << " has now " << this->_HP << " points of health left."<< std::endl;
	std::cout << "-\e[2;37m----------------- END TAKE DAMAGE ACTION -----------------\e[0m" << std::endl;
	std::cout << std::endl;
}

void FragTrap::beRepaired(unsigned int amount)
{
	std::cout << "\e[2;37m---------------- START REPAIR ACTION ----------------\e[0m" << std::endl;
	if (this->_Energy <= 0)
		std::cout << "FragTrap " << this->_name << " can't repairs itself. It has 0 energy points." << std::endl;
	else if (this->_HP <= 0)
		std::cout << "FragTrap " << this->_name << " can't repairs itself. It was destroyed." << std::endl;
	else
	{
		this->_Energy--;
		if (this->_HP + amount > 100)
		{
			std::cout << "FragTrap " << this->_name << " repairs itself with only " << amount - this->_HP << " points of health. It has reached max HP."<< std::endl;
			this->_HP = 100;
		}
		else
		{
			this->_HP += amount;
			std::cout << "FragTrap " << this->_name << " successfully repairs itself with " << amount << " points of health left."<< std::endl;
		}
		std::cout << "FragTrap " << this->_name << " has now " << this->_HP << " points of health left."<< std::endl;
	}
	std::cout << "\e[2;37m----------------- END REPAIR ACTION -----------------\e[0m" << std::endl;
	std::cout << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::string	request;

	std::cout << "\e[2;37m---------------- START HIGH FIVE ACTION ----------------\e[0m" << std::endl;
	std::cout << "FragTrap " << this->_name << " has requested a high five. Type 'Yeah' to accept the high five:" << std::endl;
	std::cin >> request;
	if (!request.compare("Yeah"))
		std::cout << "FragTrap " << this->_name << " is happy because you accepted the high five." << std::endl;
	else
		std::cout << "FragTrap " << this->_name << " is not happy because you didn't accept the high five." << std::endl;
	std::cout << "\e[2;37m---------------- END HIGH FIVE ACTION ----------------\e[0m" << std::endl;
}
