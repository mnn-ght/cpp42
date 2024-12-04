/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:32:55 by magahat           #+#    #+#             */
/*   Updated: 2024/12/04 16:14:14 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"


ClapTrap::ClapTrap(std::string name) : _name(name), hit_point(10), energy_point(10), attack_damage(0)
{
	std::cout << "ClapTrap " << name << " has been created !" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->_name << " has been destroyed !" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->energy_point == 0)
		std::cout << "ClapTrap " << this->_name << " can't attack. It has 0 energy points." << std::endl;
	else if (this->hit_point <= 0)
		std::cout << "ClapTrap " << this->_name << " can't attack. It was destroyed." << std::endl;
	else
	{
		this->energy_point--;
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->attack_damage << " points of damage!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	this->hit_point -= amount;
	std::cout << "ClapTrap " << this->_name << " is attacked (or it fell), causing " << amount << " points of damage!" << std::endl;
	if (this->hit_point <= 0)
		std::cout << "ClapTrap " << this->_name << " is destroyed!" << std::endl;
	else
		std::cout << "ClapTrap " << this->_name << " has now " << this->hit_point << " points of health left."<< std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energy_point <= 0)
		std::cout << "ClapTrap " << this->_name << " can't repairs itself. It has 0 energy points." << std::endl;
	else if (this->hit_point <= 0)
		std::cout << "ClapTrap " << this->_name << " can't repairs itself. It was destroyed." << std::endl;
	else
	{
		this->energy_point--;
		this->hit_point += amount;
		std::cout << "ClapTrap " << this->_name << " successfully repairs itself with " << amount << " points of health left."<< std::endl;
		std::cout << "ClapTrap " << this->_name << " has now " << this->hit_point << " points of health left."<< std::endl;
	}
}