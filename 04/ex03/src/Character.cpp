/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 15:22:51 by magahat           #+#    #+#             */
/*   Updated: 2024/12/14 18:37:07 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Character.hpp"

Character::Character(std::string name) : _name(name), _NbFloor(0)
{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character() : _name("NO_NAME"), _NbFloor(0)
{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character(const Character &src)
{
	*this = src;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
	}
	for (int i = 0; i < this->_NbFloor; i++)
	{
		delete this->_onFloor[i];
	}
}

Character &Character::operator=(const Character &src)
{
	this->_name = src.getName();
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
		if (src._inventory[i])
			this->_inventory[i] = src._inventory[i]->clone();
	}
	return *this;
}

std::string const & Character::getName() const
{
	return this->_name;
}

void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!this->_inventory[i])
		{
			this->_inventory[i] = m;
			break ;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx > 3)
		return ;
	if (this->_inventory[idx])
	{
		this->_onFloor[this->_NbFloor] = this->_inventory[idx];
		this->_NbFloor++;
		this->_inventory[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx > 3)
		return ;
	if (this->_inventory[idx])
		this->_inventory[idx]->use(target);
}

std::ostream	&operator<<(std::ostream& out, const ICharacter &character)
{
	out << character.getName();
	return (out);
}