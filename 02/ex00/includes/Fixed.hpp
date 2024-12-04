/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:28:43 by magahat           #+#    #+#             */
/*   Updated: 2024/12/02 16:43:55 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int	value;
	static int const nb_bits;
	
public:
	Fixed();
	Fixed(const Fixed &fixed);
	~Fixed();
	Fixed& 	operator=(const Fixed &Fixed);
	
	int		getRawBits( void ) const;
	void	setRawBits(int const raw);
};

#endif