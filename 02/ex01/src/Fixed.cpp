/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:32:55 by magahat           #+#    #+#             */
/*   Updated: 2024/12/10 13:04:30 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

/* CONSTRUCTORS */

const int Fixed::_nb_bits = 8;

Fixed::Fixed( void ) : _value(0)
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
	this->_value = int_value << this->_nb_bits;
	return ;
}

Fixed::Fixed(const float fl_value)
{
	std::cout << "Float constructor called" << std::endl;
	this->_value = (int)roundf(fl_value * (1 << this->_nb_bits));
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
		this->_value = Fixed.getRawBits();
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
	return this->_value;
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
	return ;
}

/* OTHER FUNCTIONS */

float	Fixed::toFloat( void ) const
{
	return ((float)this->_value / (1 << this->_nb_bits));
}

int		Fixed::toInt( void ) const
{
	return ((int)(roundf((float)this->_value / (1 << this->_nb_bits))));
}
