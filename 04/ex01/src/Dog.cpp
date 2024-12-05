/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:06:40 by magahat           #+#    #+#             */
/*   Updated: 2024/12/05 15:01:44 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

Dog::Dog()
{
	this->Animal::type = "Dog";
	this->_brain = new Brain();
	std::cout << "Dog class constructor called." << std::endl;
}

Dog::Dog(const Dog &dog)
{
	this->Animal::type = dog.type;
	this->_brain = new Brain(*dog._brain);
	std::cout << "Dog copy class constructor called." << std::endl;
}

Dog::~Dog()
{
	delete this->_brain;
	std::cout << "Dog class destructor called." << std::endl;
}

Dog &Dog::operator=(const Dog &dog)
{
	if (this != &dog)
	{
		this->Animal::type = dog.type;
		this->_brain = dog._brain;
	}
	return *this;
}

void	Dog::makeSound(void) const
{
	std::cout << this->getType() << " makes Woaf Woaf" << std::endl;
}

