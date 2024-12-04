/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:28:43 by magahat           #+#    #+#             */
/*   Updated: 2024/12/04 11:28:52 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int	value;
	static int const nb_bits;
	
public:
	Fixed();
	Fixed(const Fixed &fixed);
	Fixed(const int	int_value);
	Fixed(const float fl_value);
	~Fixed();

	Fixed& 	operator=(const Fixed &fixed);

	Fixed 	operator+(const Fixed &fixed) const;
	Fixed 	operator-(const Fixed &fixed) const;
	Fixed 	operator*(const Fixed &fixed) const;
	Fixed 	operator/(const Fixed &fixed) const;

	Fixed&	operator++( void );
	Fixed&	operator--( void );
	Fixed	operator++( int n );
	Fixed	operator--( int n );

	bool	operator>(const Fixed &fixed) const;
	bool	operator<(const Fixed &fixed) const;
	bool	operator>=(const Fixed &fixed) const;
	bool	operator<=(const Fixed &fixed) const;
	bool	operator==(const Fixed &fixed) const;
	bool	operator!=(const Fixed &fixed) const;
	
	int		getRawBits( void ) const;
	void	setRawBits(int const raw);
	float	toFloat( void ) const;
	int		toInt( void ) const;

	static	Fixed	min(Fixed &fixed1, Fixed &fixed2);
	static	Fixed	min(const Fixed &fixed1, const Fixed &fixed2);
	
	static	Fixed	max(Fixed &fixed1, Fixed &fixed2);
	static	Fixed	max(const Fixed &fixed1, const Fixed &fixed2);
};

std::ostream	&operator<<(std::ostream& out, const Fixed &fixed);

#endif