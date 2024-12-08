/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:06:40 by magahat           #+#    #+#             */
/*   Updated: 2024/12/05 14:39:03 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	this->WrongAnimal::type = "Animal";
	std::cout << "WrongAnimal class constructor called." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &Wronganimal)
{
	std::cout << "WrongAnimal copy class constructor called." << std::endl;
	*this = Wronganimal;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal class destructor called." << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &Wronganimal)
{
	if (this != &Wronganimal)
	{
		this->type = Wronganimal.type;
	}
	return *this;
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << this->getType() << " makes * Animal sounds *" << std::endl;
}

std::string	WrongAnimal::getType() const
{
	return this->type;
}
