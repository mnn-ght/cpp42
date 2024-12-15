/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 13:38:10 by magahat           #+#    #+#             */
/*   Updated: 2024/12/15 16:35:36 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cure.hpp"

Cure::Cure()
{
	this->AMateria::_type = "cure";
}

Cure::Cure(std::string const &type)
{
	this->AMateria::_type = type;
}

Cure::Cure(const Cure &src)
{
	*this = src;
}
		
Cure::~Cure()
{
	
}

Cure &Cure::operator=(const Cure &src)
{
	this->AMateria::_type = src.getType();
	return *this;
}

AMateria* Cure::clone() const
{
	AMateria* newCure = new Cure(*this);
	return newCure;
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target << "'s wounds *" << std::endl;
}
