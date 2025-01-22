/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:54:30 by magahat           #+#    #+#             */
/*   Updated: 2025/01/22 14:22:18 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Array.hpp"

int main( void ) {
	// int *a = new int();
	// std::cout << *a << std::endl;
	
	Array<int> a(5);
	Array<int> b;
	for (size_t i = 0; i < 5; i++)
		a[i] = i;
	
	std::cout << "\e[1;32m=== Array<int> a(5) ===\e[0m" << std::endl;
	try
	{
		std::cout << "size a = " << a.size() << std::endl;
		std::cout << "a[2] = " << a[2] << std::endl;
		std::cout << "a[10] = " << a[10] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\e[1;32m=== Array<int> b ===\e[0m" << std::endl;
	try
	{
		std::cout << "size b = " << b.size() << std::endl;
		std::cout << "b[2] = " << b[2] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << "\e[1;32m=== a = b ===\e[0m" << std::endl;
	b = a;
	try
	{
		std::cout << "size b = " << b.size() << std::endl;
		std::cout << "b[2] = " << b[2] << std::endl;
		std::cout << "b[5] = " << b[5] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	Array<int> c(a);
	std::cout << "\e[1;32m=== Array<int> c(a) ===\e[0m" << std::endl;
	try
	{
		std::cout << "size c = " << c.size() << std::endl;
		std::cout << "c[0] = " << c[0] << std::endl;
		std::cout << "c[2] = " << c[2] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	Array<std::string> d(5);
	std::cout << "\e[1;32m=== Array<std::string> d(5) ===\e[0m" << std::endl;
	for (size_t i = 0; i < 5; i++)
	{
		std::ostringstream	ofs;
		ofs << "string number " << i;
		d[i] = ofs.str();
	}
	try
	{
		std::cout << "d[2] = " << d[2] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << "\e[1;32m=== Array<std::string> e(10) && e = d ===\e[0m" << std::endl;
	Array<std::string> e(10);
	std::cout << "size before (e = d) = " << e.size() << std::endl;
	e = d;
	std::cout << "size after (e = d) = " << e.size() << std::endl;

	return 0;
}
