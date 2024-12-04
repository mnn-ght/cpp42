/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:32:55 by magahat           #+#    #+#             */
/*   Updated: 2024/12/04 10:51:45 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

/* CONSTRUCTORS */

const int Fixed::nb_bits = 8;

Fixed::Fixed( void ) : value(0)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(const Fixed &Fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = Fixed;
	return ;
}

Fixed::Fixed(const int	int_value)
{
	std::cout << "Int constructor called" << std::endl;
	this->value = int_value << this->nb_bits;
	return ;
}

Fixed::Fixed(const float fl_value)
{
	std::cout << "Float constructor called" << std::endl;
	this->value = (int)roundf(fl_value * (1 << Fixed::nb_bits));
	return ;
}

/* DESTRUCTOR */

Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

/* OPERATOR OVERLOAD */

Fixed& Fixed::operator=(const Fixed &Fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &Fixed)
		this->value = Fixed.getRawBits();
	return (*this);
}

std::ostream	&operator<<(std::ostream& out, const Fixed &Fixed)
{
	out << Fixed.toFloat();
	return out;
}

/* GET && SET */

int	Fixed::getRawBits( void ) const
{
	return this->value;
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->value = raw;
	return ;
}

/* OTHER FUNCTIONS */

float	Fixed::toFloat( void ) const
{
	return ((float)this->value / (1 << this->nb_bits));
}

int		Fixed::toInt( void ) const
{
	return ((int)(roundf((float)this->value / (1 << this->nb_bits))));
}
