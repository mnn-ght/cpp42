/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:06:40 by magahat           #+#    #+#             */
/*   Updated: 2024/12/05 14:31:31 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

Cat::Cat()
{
	this->Animal::type = "Cat";
	std::cout << "Cat class constructor called." << std::endl;
}

Cat::Cat(const Cat &cat)
{
	std::cout << "Cat copy class constructor called." << std::endl;
	*this = cat;
}

Cat::~Cat()
{
	std::cout << "Cat class destructor called." << std::endl;
}

Cat &Cat::operator=(const Cat &cat)
{
	if (this != &cat)
	{
		this->Animal::type = cat.type;
	}
	return *this;
}

void	Cat::makeSound(void) const
{
	std::cout << this->getType() << " makes Miaou Miaou" << std::endl;
}

