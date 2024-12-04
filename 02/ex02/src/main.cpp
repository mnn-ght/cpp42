/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:54:30 by magahat           #+#    #+#             */
/*   Updated: 2024/12/04 12:52:02 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

int main( void )
{
	Fixed		a;
	Fixed const	b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed const	c( Fixed( 0.02f ) );
	
	std::cout << std::endl << "a (expected '0') >> " << a << std::endl;
	std::cout << "++a (expected '0.00390625') >> " << ++a << std::endl;
	std::cout << "a (expected '0.00390625') >> " << a << std::endl;
	std::cout << "a++ (expected '0.00390625') >> " << a++ << std::endl;
	std::cout << "a (expected '0.0078125') >> " << a << std::endl;

	std::cout << "b (expected '10.1016') >> " << b << std::endl;
	
	std::cout << "max between a and b (expected '10.1016') >> " << Fixed::max( a, b ) << std::endl;

	std::cout << std::endl << "Other tests" << std::endl;
	std::cout << "a + a = " << a + a << std::endl;
	std::cout << "a * 2 = " << a * Fixed( 2 ) << std::endl;
	std::cout << "a - a = " << a - a << std::endl;
	std::cout << "a - a  - a = " << a - a - a << std::endl << std::endl;
	
	std::cout << "a + b = " << a + b << std::endl;
	std::cout << "a - b = " << a - b << std::endl;
	std::cout << "a * b = " << a * b << std::endl;
	std::cout << "a / b = " << a / b << std::endl << std::endl;
	
	std::cout << "is a > b ? (expected 0) >> " << (a > b) << std::endl;
	std::cout << "is a < b ? (expected 1) >> " << (a < b) << std::endl;
	std::cout << "is a == b ? (expected 0) >> " << (a == b) << std::endl;
	std::cout << "is a != b ? (expected 1) >> " << (a != b) << std::endl << std::endl;

	std::cout << "c >> " << c << std::endl;

	std::cout << "a + c = " << a + c << std::endl;
	std::cout << "a - c = " << a - c << std::endl;
	std::cout << "a * c = " << a * c << std::endl;
	std::cout << "a / c = " << a / c << std::endl;
	return 0;
}
