/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:06:40 by magahat           #+#    #+#             */
/*   Updated: 2024/12/07 16:47:41 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"

Animal::Animal()
{
	this->Animal::type = "Animal";
	std::cout << "Animal class constructor called." << std::endl;
}

Animal::Animal(const Animal &animal)
{
	std::cout << "Animal copy class constructor called." << std::endl;
	*this = animal;
}

Animal::~Animal()
{
	std::cout << "Animal class destructor called." << std::endl;
}

Animal &Animal::operator=(const Animal &animal)
{
	if (this != &animal)
	{
		this->type = animal.type;
	}
	return *this;
}

void	Animal::makeSound(void) const
{
	std::cout << this->getType() << " makes no sound" << std::endl;
}

std::string	Animal::getType() const
{
	return this->type;
}
