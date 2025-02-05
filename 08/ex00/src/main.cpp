/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:54:30 by magahat           #+#    #+#             */
/*   Updated: 2025/02/05 14:08:06 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/easyfind.hpp"
#include <map>
#include <list>
#include <vector>
#include <deque>

#define TEST(nb, type) {std::cout << std::endl << "\e[1;32m========= TEST " << nb << " with container type : \e[1;34m" << type << "\e[1;32m =========\e[0m" << std::endl;}

int main( void ) {
	int i = 1;
	std::list<int> lst1;
	std::list<int> lst2;
	std::vector<int> v1;
	std::deque<int> d1;

	lst1.push_back(1);
	lst1.push_back(42);
	lst1.push_back(100);
	v1.push_back(1);
	v1.push_back(42);
	v1.push_back(100);
	d1.push_back(1);
	d1.push_back(42);
	d1.push_back(100);
	
	TEST(i++, "list<int> remplie de 3 int {1, 42, 100}");
	try
	{
		std::cout << *easyfind(lst1, 100) << std::endl;
		std::cout << *easyfind(lst1, 0) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	TEST(i++, "list<int> vide");
	try
	{
		std::cout << *easyfind(lst2, 0) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	TEST(i++, "vector<int> remplie de 3 int {1, 42, 100}");
	try
	{
		std::cout << *easyfind(v1, 1) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	TEST(i++, "deque<int> remplie de 3 int {1, 42, 100}");
	try
	{
		std::cout << *easyfind(d1, 42) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	for (int i = 0; i < 100; i++)
		lst2.push_back(i + 1);
	
	TEST(i++, "list<int> remplie de 100 int de 1 a 100");
	try
	{
		std::cout << *easyfind(lst2, 42) << std::endl;
		std::cout << *easyfind(lst2, 100) << std::endl;
		std::cout << *easyfind(lst2, -42) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	return 0;
}
