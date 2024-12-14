/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:07:59 by magahat           #+#    #+#             */
/*   Updated: 2024/12/14 14:59:48 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AMateria.hpp"

AMateria::AMateria()
{
	
}

AMateria::AMateria(std::string const & type) : _type(type)
{
	
}

AMateria::AMateria(const AMateria &materia)
{
	*this = materia;
}

AMateria::~AMateria()
{
	
}

AMateria &AMateria::operator=(const AMateria &materia)
{
	this->_type = materia.getType();
	return *this;
}

std::ostream	&operator<<(std::ostream& out, const AMateria &materia)
{
	out << materia.getType();
	return out;
}

std::string const & AMateria::getType() const
{
	return this->_type;
}

/* AMateria* AMateria::clone() const
{
	AMateria *newMat;
	
	*newMat = *this;
	return newMat;
} */

void AMateria::use(ICharacter& target)
{
	std::cout << "* use the materia at " << target << " *" << std::endl;
}