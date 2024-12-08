/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:06:40 by magahat           #+#    #+#             */
/*   Updated: 2024/12/08 16:00:51 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog class constructor called." << std::endl;
	this->A_Animal::type = "Dog";
	this->_brain = new Brain();
}

Dog::Dog(const Dog &dog)
{
	std::cout << "Dog copy class constructor called." << std::endl;
	this->A_Animal::type = dog.type;
	this->_brain = new Brain(*dog._brain);
}

Dog::~Dog()
{
	std::cout << "Dog class destructor called." << std::endl;
	delete this->_brain;
}

Dog &Dog::operator=(const Dog &dog)
{
	if (this != &dog)
	{
		this->A_Animal::type = dog.type;
		this->_brain = dog._brain;
	}
	return *this;
}

void	Dog::makeSound(void) const
{
	std::cout << this->getType() << " makes Woaf Woaf" << std::endl;
}

void	Dog::think(int index_idea) const
{
	std::cout << this->_brain->get_idea(index_idea) << " is in " << this->type << " brain." << std::endl;
}
