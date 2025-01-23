/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:34:28 by magahat           #+#    #+#             */
/*   Updated: 2025/01/23 11:25:20 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <exception>
#include <vector>
#include <cstdlib>
#include <iterator>

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
	void addMoreNumber(std::vector<int>::iterator first, std::vector<int>::iterator last);
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

};

std::ostream	&operator<<(std::ostream& out, const Span &storage);

#endif