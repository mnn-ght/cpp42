/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:34:28 by magahat           #+#    #+#             */
/*   Updated: 2025/02/05 15:13:27 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <exception>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <iterator>
#include <numeric>

class Span
{
private:
	unsigned int _maxN;
	std::vector<int> _stock;
	
public:
	Span(unsigned int N);
	Span();
	Span(const Span &other);

	Span &operator=(const Span &other);

	~Span();
	
	void addNumber(int nb);
	long shortestSpan();
	long longestSpan();

	const unsigned int &getMaxSize() const;
	const std::vector<int> &getStock() const;

	class MaxElementInStoreException : public std::exception {
		const char* what() const throw();
	};
	
	class NoSpanFoundException : public std::exception {
		const char* what() const throw();
	};

	class NoAddMoreNumber : public std::exception {
		const char* what() const throw();
	};

	/* template <typename InputIt>
	void addMoreNumber(InputIt first, InputIt last) {
		std::srand(time(NULL));
		if (std::distance(first, last) > 0)
		{
			for (; first < last; first++)
			{
				try
				{
					addNumber(std::rand());
				}
				catch(const std::exception& e)
				{
					std::cerr << e.what() << std::endl;
					return ;
				}
			}
		}
	}; */

	void addMoreNumber(std::vector<int>::iterator first, std::vector<int>::iterator last);

};

std::ostream	&operator<<(std::ostream& out, const Span &storage);

#endif