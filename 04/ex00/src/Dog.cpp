/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:06:40 by magahat           #+#    #+#             */
/*   Updated: 2024/12/05 14:31:35 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

Dog::Dog()
{
	this->Animal::type = "Dog";
	std::cout << "Dog class constructor called." << std::endl;
}

Dog::Dog(const Dog &dog)
{
	std::cout << "Dog copy class constructor called." << std::endl;
	*this = dog;
}

Dog::~Dog()
{
	std::cout << "Dog class destructor called." << std::endl;
}

Dog &Dog::operator=(const Dog &dog)
{
	if (this != &dog)
	{
		this->Animal::type = dog.type;
	}
	return *this;
}

void	Dog::makeSound(void) const
{
	std::cout << this->getType() << " makes Woaf Woaf" << std::endl;
}

