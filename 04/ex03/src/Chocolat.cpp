/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Chocolat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 13:38:10 by magahat           #+#    #+#             */
/*   Updated: 2024/12/14 18:12:02 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Chocolat.hpp"

Chocolat::Chocolat()
{
	this->AMateria::_type = "chocolat";
}

Chocolat::Chocolat(std::string const &type)
{
	this->AMateria::_type = type;
}

Chocolat::Chocolat(const Chocolat &src)
{
	*this = src;
}
		
Chocolat::~Chocolat()
{
	
}

Chocolat &Chocolat::operator=(const Chocolat &src)
{
	this->AMateria::_type = src.getType();
	return *this;
}

AMateria* Chocolat::clone() const
{
	AMateria* newChocolat = new Chocolat(*this);
	return newChocolat;
}

void Chocolat::use(ICharacter& target)
{
	std::cout << "* eats a chocolate bar with " << target << " *" << std::endl;
}
