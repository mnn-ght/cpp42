/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:54:30 by magahat           #+#    #+#             */
/*   Updated: 2025/01/20 15:12:16 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/whatever.hpp"

int main( void ) {
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << "\t\t\e[2;31mShould output = 'a = 3, b = 2'\e[0m" << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << "\t\t\e[2;31mShould output = 'min(a, b) = 2'\e[0m" << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << "\t\t\e[2;31mShould output = 'max(a, b) = 3'\e[0m" << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << "\t\t\e[2;31mShould output = 'c = chaine2, d = chaine1'\e[0m" << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << "\t\t\e[2;31mShould output = 'min(c, d) = chaine1'\e[0m" << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << "\t\t\e[2;31mShould output = 'max(c, d) = chaine2'\e[0m" << std::endl;
	return 0;
}
