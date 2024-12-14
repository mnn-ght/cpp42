/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 13:38:10 by magahat           #+#    #+#             */
/*   Updated: 2024/12/14 18:12:02 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Ice.hpp"

Ice::Ice()
{
	this->AMateria::_type = "ice";
}

Ice::Ice(std::string const &type)
{
	this->AMateria::_type = type;
}

Ice::Ice(const Ice &src)
{
	*this = src;
}
		
Ice::~Ice()
{
	
}

Ice &Ice::operator=(const Ice &src)
{
	this->AMateria::_type = src.getType();
	return *this;
}

AMateria* Ice::clone() const
{
	AMateria* newIce = new Ice(*this);
	return newIce;
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target << " *" << std::endl;
}
