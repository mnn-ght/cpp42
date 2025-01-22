/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:54:30 by magahat           #+#    #+#             */
/*   Updated: 2025/01/22 15:17:01 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/easyfind.hpp"
#include <map>
#include <list>
#include <vector>
#include <deque>

int main( void ) {
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
	
	try
	{
		std::list<int>::iterator result = easyfind(lst1, 100);
		std::cout << *result << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		std::list<int>::iterator result = easyfind(lst2, 0);
		std::cout << *result << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	try
	{
		std::vector<int>::iterator result = easyfind(v1, 1);
		std::cout << *result << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		std::deque<int>::iterator result = easyfind(d1, 42);
		std::cout << *result << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
