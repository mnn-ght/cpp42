/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:32:55 by magahat           #+#    #+#             */
/*   Updated: 2024/12/10 13:18:15 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

/*
	CONSTRUCTORS
*/

const int Fixed::nb_bits = 8;

Fixed::Fixed( void ) : value(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed::Fixed(const int	int_value) : value(int_value << nb_bits)
{
	// std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float fl_value) : value((int)roundf(fl_value * (1 << nb_bits)))
{
	// std::cout << "Float constructor called" << std::endl;
}

/*
	DESTRUCTOR
*/

Fixed::~Fixed( void )
{
	// std::cout << "Destructor called" << std::endl;
}

/*
	OPERATOR OVERLOAD
*/

Fixed& Fixed::operator=(const Fixed &fixed)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed)
		this->value = fixed.getRawBits();
	return (*this);
}

Fixed Fixed::operator+(const Fixed &fixed) const
{
	return Fixed(fixed.toFloat() + this->toFloat());
}

Fixed Fixed::operator-(const Fixed &fixed) const
{
	return Fixed(this->toFloat() - fixed.toFloat());
}

Fixed Fixed::operator*(const Fixed &fixed) const
{
	return Fixed(fixed.toFloat() * this->toFloat());
}

Fixed Fixed::operator/(const Fixed &fixed) const
{
	return Fixed(fixed.toFloat() / this->toFloat());
}

Fixed& Fixed::operator++( void )
{
	this->value++;
	return (*this);
}

Fixed& Fixed::operator--( void )
{
	this->value--;
	return (*this);
}

Fixed Fixed::operator++( int n )
{
	Fixed	tmp = *this;
	
	if (n < 0)
	{
		while (n <= 0)
		{
			--*this;
			n++;
		}
	}
	else
	{
		while (n >= 0)
		{
			++*this;
			n--;
		}
	}
	return (tmp);
}

Fixed Fixed::operator--( int n )
{
	Fixed	tmp = *this;
	
	if (n < 0)
	{
		while (n <= 0)
		{
			++*this;
			n++;
		}
	}
	else
	{
		while (n >= 0)
		{
			--*this;
			n--;
		}
	}
	return (tmp);
}

bool	Fixed::operator>(const Fixed &fixed) const
{
	return (this->toFloat() > fixed.toFloat());
}

bool	Fixed::operator<(const Fixed &fixed) const
{
	return (this->toFloat() < fixed.toFloat());
}

bool	Fixed::operator>=(const Fixed &fixed) const
{
	return (this->toFloat() >= fixed.toFloat());
}

bool	Fixed::operator<=(const Fixed &fixed) const
{
	return (this->toFloat() <= fixed.toFloat());
}

bool	Fixed::operator==(const Fixed &fixed) const
{
	return (this->toFloat() == fixed.toFloat());
}

bool	Fixed::operator!=(const Fixed &fixed) const
{
	return (this->toFloat() != fixed.toFloat());
}

std::ostream	&operator<<(std::ostream& out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}

/*
	GET && SET
*/

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

/*
	OTHER FUNCTIONS
*/

float	Fixed::toFloat( void ) const
{
	return ((float)this->value / (1 << this->nb_bits));
}

int		Fixed::toInt( void ) const
{
	return ((int)(roundf((float)this->value / (1 << this->nb_bits))));
}

Fixed	&Fixed::min(Fixed &fixed1, Fixed &fixed2)
{
	if (fixed1 > fixed2)
		return (fixed2);
	return (fixed1);
}

Fixed	const &Fixed::min(const Fixed &fixed1, const Fixed &fixed2)
{
	if (fixed1 > fixed2)
		return (fixed2);
	return (fixed1);
}

Fixed	&Fixed::max(Fixed &fixed1, Fixed &fixed2)
{
	if (fixed1 >= fixed2)
		return (fixed1);
	return (fixed2);
}

Fixed	const &Fixed::max(const Fixed &fixed1, const Fixed &fixed2)
{
	if (fixed1 >= fixed2)
		return (fixed1);
	return (fixed2);
}