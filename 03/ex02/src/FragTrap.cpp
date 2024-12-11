/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:20:29 by magahat           #+#    #+#             */
/*   Updated: 2024/12/11 15:28:11 by magahat          ###   ########.fr       */
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

FragTrap::FragTrap( void ) : ClapTrap("NO_NAME")
{
	this->_HP = 100;
	this->_Energy = 100;
	this->_Damage = 30;
	std::cout << "\e[1;32mFragTrap NO_NAME has been created !\e[0m" << std::endl;
}

FragTrap::FragTrap(const FragTrap &flp)
{
	*this = flp;
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

std::ostream	&operator<<(std::ostream& out, const FragTrap &fragTrap)
{
	out << fragTrap.getName();
	return out;
}

/*
	MEMBER FUNCTIONS
*/

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
