/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 15:22:51 by magahat           #+#    #+#             */
/*   Updated: 2024/12/15 17:48:13 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Character.hpp"

Character::Character(std::string name) : _name(name), _NbOnFloor(0)
{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character() : _name("NO_NAME"), _NbOnFloor(0)
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
	if (this->_NbOnFloor > 0)
		this->_OnFloor->delete_nodes();
	this->_NbOnFloor = 0;
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
	if (this->_NbOnFloor > 0)
		this->_OnFloor->delete_nodes();
	this->_NbOnFloor = 0;
	return *this;
}

std::string const & Character::getName() const
{
	return this->_name;
}

void Character::equip(AMateria* m)
{
	int j = 0;
	
	for (int i = 0; i < 4; i++)
	{
		if (!this->_inventory[i])
		{
			this->_inventory[i] = m;
			j = 1;
			break ;
		}
	}
	if (j == 0)
		std::cout << "\e[31mInventory is full. Unequip a Materia to equip a new one.\e[0m" << std::endl;
}

void Character::unequip(int idx)
{
	if (idx > 3)
	{
		std::cout << "\e[31mIndex not in range of inventory : choose a number between 0 and 3.\e[0m" << std::endl;
		return ;
	}
	if (this->_inventory[idx])
	{
		if (this->_NbOnFloor == 0)
			this->_OnFloor = new OnFloor(this->_inventory[idx]);
		else
			this->_OnFloor->add_node(this->_inventory[idx]);
		this->_NbOnFloor++;
		std::cout << "\e[34m" << *this->_inventory[idx] << " Materia was unequipped successfully from " << this->_name << "'s inventory.\e[0m" << std::endl;
		this->_inventory[idx] = NULL;
	}
	else
		std::cout << "\e[31mNo Materia to unequip in the inventory emplacement.\e[0m" << std::endl;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx > 3 || idx < 0)
	{
		std::cout << "\e[31mIndex not in range of inventory : choose a number between 0 and 3.\e[0m" << std::endl;
		return ;
	}
	if (this->_inventory[idx])
		this->_inventory[idx]->use(target);
	else
		std::cout << "\e[31mNo Materia to use in the inventory emplacement.\e[0m" << std::endl;
}

void Character::getstatus() const
{
	OnFloor* tmp;
	
	if (this->_NbOnFloor > 0)
		tmp = this->_OnFloor->go_first_node();
	std::cout << "\e[1;32m---------------------\e[0m" << std::endl;
	std::cout << "\e[3;32mCharacter's name : " << this->_name << std::endl;
	if (this->_inventory[0])
		std::cout << "Inventory[0] : " << *this->_inventory[0] << std::endl;
	if (this->_inventory[1])
		std::cout << "Inventory[1] : " << *this->_inventory[1] << std::endl;
	if (this->_inventory[2])
		std::cout << "Inventory[2] : " << *this->_inventory[2] << std::endl;
	if (this->_inventory[3])
		std::cout << "Inventory[3] : " << *this->_inventory[3] << std::endl;
	std::cout << "Number of materia on the floor (that was unequiped) : " << this->_NbOnFloor << std::endl;
	
	for (int i = 0; i < this->_NbOnFloor; i++)
	{
		std::cout << "Materia on the floor number " << i << " : " << *tmp->getMateria() << std::endl;
		tmp = tmp->getNext();
	}
	std::cout << "\e[1;32m---------------------\e[0m" << std::endl;
}

std::ostream	&operator<<(std::ostream& out, const ICharacter &character)
{
	out << character.getName();
	return (out);
}
