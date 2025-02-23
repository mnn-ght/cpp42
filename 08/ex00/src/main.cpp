/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:54:30 by magahat           #+#    #+#             */
/*   Updated: 2025/02/23 11:29:19 by magahat          ###   ########.fr       */
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
	
	{
		TEST(i++, "list<int> remplie de 3 int {1, 42, 100}");
		std::list<int> lst;
		lst.push_back(1);
		lst.push_back(42);
		lst.push_back(100);
		
		try {

			std::cout << *easyfind(lst, 1) << std::endl;
			std::cout << *easyfind(lst, 42) << std::endl;
			std::cout << *easyfind(lst, 100) << std::endl;
			std::cout << *easyfind(lst, 43) << std::endl;
		
		} catch(const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}
	
	{
		TEST(i++, "list<int> vide");
		std::list<int> lst;
		
		try {
		
			std::cout << *easyfind(lst, 0) << std::endl;
		
		} catch(const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}
	
	{
		TEST(i++, "vector<int> remplie de 3 int {1, 42, 100}");
		std::vector<int> vct;
		vct.push_back(1);
		vct.push_back(42);
		vct.push_back(100);
		
		try {
		
			std::cout << *easyfind(vct, 1) << std::endl;
			std::cout << *easyfind(vct, 42) << std::endl;
			std::cout << *easyfind(vct, 100) << std::endl;
			std::cout << *easyfind(vct, 101) << std::endl;
		
		} catch(const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}
	
	{
		TEST(i++, "deque<int> remplie de 3 int {1, 42, 100}");
		std::deque<int> dq;
		dq.push_back(1);
		dq.push_back(42);
		dq.push_back(100);
		
		try {
			
			std::cout << *easyfind(dq, 1) << std::endl;
			std::cout << *easyfind(dq, 42) << std::endl;
			std::cout << *easyfind(dq, 100) << std::endl;
			std::cout << *easyfind(dq, 2) << std::endl;
			
		} catch(const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}
	
	{
		std::list<int> lst;
		for (int i = 0; i < 100; i++)
			lst.push_back(i + 1);
		
		TEST(i++, "list<int> remplie de 100 int de 1 a 100");
		try {
		
			std::cout << *easyfind(lst, 5) << std::endl;
			std::cout << *easyfind(lst, 42) << std::endl;
			std::cout << *easyfind(lst, 50) << std::endl;
			std::cout << *easyfind(lst, 78) << std::endl;
			std::cout << *easyfind(lst, 100) << std::endl;
			std::cout << *easyfind(lst, -42) << std::endl;
		
		} catch(const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}
	
	return 0;
}
