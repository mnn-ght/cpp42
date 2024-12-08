/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A_Animal.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:06:40 by magahat           #+#    #+#             */
/*   Updated: 2024/12/08 16:00:32 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/A_Animal.hpp"

A_Animal::A_Animal()
{
	std::cout << "A_Animal class constructor called." << std::endl;
	this->A_Animal::type = "A_Animal";
}

A_Animal::A_Animal(const A_Animal &A_Animal)
{
	std::cout << "A_Animal copy class constructor called." << std::endl;
	*this = A_Animal;
}

A_Animal::~A_Animal()
{
	std::cout << "A_Animal class destructor called." << std::endl;
}

A_Animal &A_Animal::operator=(const A_Animal &A_Animal)
{
	if (this != &A_Animal)
	{
		this->type = A_Animal.type;
	}
	return *this;
}

void	A_Animal::makeSound(void) const
{
	std::cout << this->getType() << " makes no sound" << std::endl;
}

std::string	A_Animal::getType() const
{
	return this->type;
}
