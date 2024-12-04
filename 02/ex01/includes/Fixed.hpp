/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:28:43 by magahat           #+#    #+#             */
/*   Updated: 2024/12/04 10:22:29 by magahat          ###   ########.fr       */
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
	Fixed& 	operator=(const Fixed &Fixed);
	
	int		getRawBits( void ) const;
	void	setRawBits(int const raw);
	float	toFloat( void ) const;
	int		toInt( void ) const;
};

std::ostream	&operator<<(std::ostream& out, const Fixed &Fixed);

#endif