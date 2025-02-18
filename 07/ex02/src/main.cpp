/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:54:30 by magahat           #+#    #+#             */
/*   Updated: 2025/02/18 16:21:25 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include "../includes/Array.hpp"
#define MAX_VAL 750

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
	
	std::cout << "\e[1;32m=== b = a ===\e[0m" << std::endl;
	b = a;
	try
	{
		std::cout << "size b = " << b.size() << std::endl;
		b[2] = 40;
		std::cout << "b[2] = " << b[2] << std::endl;
		std::cout << "b[5] = " << b[5] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	const Array<int> c(a);
	std::cout << "\e[1;32m=== Array<int> c(a) ===\e[0m" << std::endl;
	try
	{
		std::cout << "size c = " << c.size() << std::endl;
		// c[2] = 40;
		std::cout << "c[0] = " << c[0] << std::endl;
		std::cout << "c[2] = " << c[2] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	Array<std::string> d(5);
	std::cout << "\e[1;32m=== Array<std::string> d(5) ===\e[0m" << std::endl;
	for (size_t i = 0; i < 5; i++) {
		std::ostringstream	ofs;
		ofs << "string number " << i;
		d[i] = ofs.str();
	}
	try
	{
		std::cout << "d[2] = " << d[2] << std::endl;
		std::cout << "d[5] = " << d[5] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << "\e[1;32m=== Array<std::string> f(10) && f = d ===\e[0m" << std::endl;
	Array<std::string> f(10);
	std::cout << "size of f before (f = d) = " << f.size() << std::endl;
	std::cout << "size d = " << d.size() << std::endl;
	f = d;
	std::cout << "size of f after (f = d) = " << f.size() << std::endl;
	try
	{
		std::cout << "f[2] = " << f[2] << std::endl;
		std::cout << "f[5] = " << f[-2] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << "\e[1;32m=== Test subject ===\e[0m" << std::endl;

    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}