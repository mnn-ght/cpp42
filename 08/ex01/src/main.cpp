/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:54:30 by magahat           #+#    #+#             */
/*   Updated: 2025/01/23 12:28:06 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"

int main()
{
	std::cout << "\e[1;32m=========== TEST MAIN ===========\e[0m" << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << "Shortest Span = " << sp.shortestSpan() << std::endl;
	std::cout << "Longest Span = " << sp.longestSpan() << std::endl;

	std::cout << "\e[1;32m=========== TEST error add 1 more ===========\e[0m" << std::endl;
	try
	{
		std::cout << sp;
		sp.addNumber(111);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\e[1;32m=========== TEST error span ===========\e[0m" << std::endl;

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
		std::cout << "Shortest Span = " << st.shortestSpan() << std::endl;
		std::cout << "Longest Span = " << st.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}



	std::cout << "\e[1;32m=========== TEST bcp de nombres (random) ===========\e[0m" << std::endl;

	Span so(10000);
	std::vector<int> x;
	try
	{
		so.addMoreNumber(x.begin(), x.begin() + 10000);
		std::cout << so;
		std::cout << "Shortest Span = " << so.shortestSpan() << std::endl;
		std::cout << "Longest Span = " << so.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}