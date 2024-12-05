/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:06:40 by magahat           #+#    #+#             */
/*   Updated: 2024/12/05 15:19:05 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

Cat::Cat()
{
	this->Animal::type = "Cat";
	this->_brain = new Brain();
	std::cout << "Cat class constructor called." << std::endl;
}

Cat::Cat(const Cat &cat)
{
	this->Animal::type = cat.type;
	this->_brain = new Brain(*cat._brain);
	std::cout << "Cat copy class constructor called." << std::endl;
}

Cat::~Cat()
{
	delete this->_brain;
	std::cout << "Cat class destructor called." << std::endl;
}

Cat &Cat::operator=(const Cat &cat)
{
	if (this != &cat)
	{
		this->Animal::type = cat.type;
		this->_brain = cat._brain;
	}
	return *this;
}

void	Cat::makeSound(void) const
{
	std::cout << this->getType() << " makes Miaou Miaou" << std::endl;
}

void	Cat::think(void) const
{
	std::cout << get_brain() << " makes Miaou Miaou" << std::endl;
}