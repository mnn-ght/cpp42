/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:54:30 by magahat           #+#    #+#             */
/*   Updated: 2025/01/22 12:03:13 by magahat          ###   ########.fr       */
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
	
	/* int x = 1;
	int y = 3;
	double d1 = 5.6;
	double d2 = -9.4;
	float f1 = 342.0f;
	float f2 = -2.44f;
	char c1 = 'g';
	char c2 = 'H';
	std::string s1 = "hello world";
	std::string s2 = "goodbye";
	int *ptr1 = &x;
	int *ptr2 = &y;

	std::cout << std::endl;
	std::cout << "==================== INT ====================" << std::endl;
	std::cout << "BEFORE SWAP" << std ::endl << "x = " << x << std::endl << "y = " << y << std::endl;
	::swap(x, y) ;
	std::cout << "AFTER SWAP" << std ::endl << "x = " << x << std::endl << "y = " << y << std::endl;
	std::cout << std::endl;
	std::cout << "==================== DOUBLE ====================" << std::endl;
	std::cout << "BEFORE SWAP" << std ::endl << "d1 = " << d1 << std::endl << "d2 = " << d2 << std::endl;
	::swap(d1, d2) ;
	std::cout << "AFTER SWAP" << std ::endl << "d1 = " << d1 << std::endl << "d2 = " << d2 << std::endl;
	std::cout << std::endl;
	std::cout << "==================== FLOAT ====================" << std::endl;
	std::cout << "BEFORE SWAP" << std ::endl << "f1 = " << f1 << std::endl << "f2 = " << f2 << std::endl;
	::swap(f1, f2) ;
	std::cout << "AFTER SWAP" << std ::endl << "f1 = " << f1 << std::endl << "f2 = " << f2 << std::endl;
	std::cout << std::endl;
	std::cout << "==================== CHAR ====================" << std::endl;
	std::cout << "BEFORE SWAP" << std ::endl << "c1 = " << c1 << std::endl << "c2 = " << c2 << std::endl;
	::swap(c1, c2) ;
	std::cout << "AFTER SWAP" << std ::endl << "c1 = " << c1 << std::endl << "c2 = " << c2 << std::endl;
	std::cout << std::endl;
	std::cout << "==================== STRING ====================" << std::endl;
	std::cout << "BEFORE SWAP" << std ::endl << "s1 = " << s1 << std::endl << "s2 = " << s2 << std::endl;
	::swap(s1, s2) ;
	std::cout << "AFTER SWAP" << std ::endl << "s1 = " << s1 << std::endl << "s2 = " << s2 << std::endl;
	std::cout << std::endl;
	std::cout << "==================== PTR ====================" << std::endl;
	std::cout << "BEFORE SWAP" << std ::endl << "ptr1 = " << ptr1 << std::endl << "ptr2 = " << ptr2 << std::endl;
	::swap(ptr1, ptr2) ;
	std::cout << "AFTER SWAP" << std ::endl << "ptr1 = " << ptr1 << std::endl << "ptr2 = " << ptr2 << std::endl;

	std::cout << "==================== VALUE PTR ====================" << std::endl;
	std::cout << "BEFORE SWAP" << std ::endl << "*ptr1 = " << *ptr1 << std::endl << "*ptr2 = " << *ptr2 << std::endl;
	::swap(*ptr1, *ptr2) ;
	std::cout << "AFTER SWAP" << std ::endl << "*ptr1 = " << *ptr1 << std::endl << "*ptr2 = " << *ptr2 << std::endl; */
	
	return 0;
}
