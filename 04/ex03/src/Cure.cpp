/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 13:38:10 by magahat           #+#    #+#             */
/*   Updated: 2024/12/14 15:19:55 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cure.hpp"

Cure::Cure() : AMateria()
{
	
}

Cure::Cure(std::string const &type) : AMateria(type)
{
	
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
	this->_type = src.getType();
	return *this;
}

AMateria* Cure::clone() const
{
	AMateria* newCure = new Cure(*this);
	return newCure;
}

void Cure::use(ICharacter& target)
{
	std::cout << "* shoots an Cure bolt at " << target << " *" << std::endl;
}
