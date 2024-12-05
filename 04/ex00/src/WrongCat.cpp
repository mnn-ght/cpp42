/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:06:40 by magahat           #+#    #+#             */
/*   Updated: 2024/12/05 14:38:40 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongCat.hpp"

WrongCat::WrongCat()
{
	this->WrongAnimal::type = "Cat";
	std::cout << "WrongCat class constructor called." << std::endl;
}

WrongCat::WrongCat(const WrongCat &Wrongcat)
{
	std::cout << "WrongCat copy class constructor called." << std::endl;
	*this = Wrongcat;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat class destructor called." << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &Wrongcat)
{
	if (this != &Wrongcat)
	{
		this->WrongAnimal::type = Wrongcat.type;
	}
	return *this;
}

void	WrongCat::makeSound(void) const
{
	std::cout << this->getType() << " makes Miaou Miaou" << std::endl;
}

