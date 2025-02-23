/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:54:30 by magahat           #+#    #+#             */
/*   Updated: 2025/02/23 11:37:55 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"
#define TEST(nb, type) {std::cout << std::endl << "\e[1;32m========= TEST " << nb << " \e[1;34m" << type << "\e[1;32m =========\e[0m" << std::endl;}

int main()
{
	int i = 1;
	TEST(i++, "du sujet");
	
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << "Shortest Span = " << sp.shortestSpan() << std::endl; // 2
	std::cout << "Longest Span = " << sp.longestSpan() << std::endl; // 14

	TEST(i++, "error add 1 more");
	try
	{
		std::cout << sp;
		sp.addNumber(111);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	TEST(i++, "error span");
	Span st(2);
	try
	{
		std::cout << st;
		std::cout << "Shortest Span = " << st.shortestSpan() << std::endl;
		std::cout << "Longest Span = " << st.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	try
	{
		st.addNumber(42);
		std::cout << st;
		std::cout << "Shortest Span = " << st.shortestSpan() << std::endl;
		std::cout << "Longest Span = " << st.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	try
	{
		st.addNumber(-42);
		std::cout << st;
		std::cout << "Shortest Span = " << st.shortestSpan() << std::endl; // 84
		std::cout << "Longest Span = " << st.longestSpan() << std::endl; // 84
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}


	TEST(i++, "bcp de nombres (99)");

	Span so(99);
	std::vector<int> x;
	try
	{
		so.addMoreNumber(x.begin(), x.begin() + 99);
		std::cout << so;
		std::cout << "Shortest Span = " << so.shortestSpan() << std::endl;
		std::cout << "Longest Span = " << so.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}


	TEST(i++, "encore plus de nombres (10 000)");

	Span stock(10000);
	std::vector<int> y;
	try
	{
		stock.addMoreNumber(y.begin(), y.begin() + 10000);
		std::cout << stock;
		std::cout << "Shortest Span = " << stock.shortestSpan() << std::endl;
		std::cout << "Longest Span = " << stock.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}