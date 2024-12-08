/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:06:40 by magahat           #+#    #+#             */
/*   Updated: 2024/12/08 16:00:43 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat class constructor called." << std::endl;
	this->A_Animal::type = "Cat";
	this->_brain = new Brain();
}

Cat::Cat(const Cat &cat)
{
	std::cout << "Cat copy class constructor called." << std::endl;
	this->A_Animal::type = cat.type;
	this->_brain = new Brain(*cat._brain);
}

Cat::~Cat()
{
	std::cout << "Cat class destructor called." << std::endl;
	delete this->_brain;
}

Cat &Cat::operator=(const Cat &cat)
{
	if (this != &cat)
	{
		this->A_Animal::type = cat.type;
		this->_brain = cat._brain;
	}
	return *this;
}

void	Cat::makeSound(void) const
{
	std::cout << this->getType() << " makes Miaou Miaou" << std::endl;
}

void	Cat::think(int index_idea) const
{
	std::cout << this->_brain->get_idea(index_idea) << " is in " << this->type << " brain." << std::endl;
}