/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:28:22 by magahat           #+#    #+#             */
/*   Updated: 2025/01/23 11:55:03 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"

/*
	CONSTRUCTORS
*/

Span::Span(unsigned int N) : _maxN(N), _stock() {
}

Span::Span(void) :  _maxN(0), _stock() {
}

Span::Span(const Span &other) {
	*this = other;
}

/*
	DESTRUCTORS
*/

Span::~Span() {
}

/*
	OPERATORS OVERLOAD
*/

Span &Span::operator=(const Span &other)
{
	_maxN = other._maxN;
	_stock.clear();
	_stock = other._stock;
	return (*this);
}

std::ostream	&operator<<(std::ostream& out, const Span &storage)
{
	out << "This storage has actually " << storage.getStock().size() << " numbers in stock." << std::endl;
	out << "It can store " << storage.getMaxSize() << " maximum. It can accept " << storage.getMaxSize() - storage.getStock().size() << " numbers in stock." << std::endl;
	if (storage.getStock().size() > 0 && storage.getStock().size() < 100)
	{
		out << "Here are the numbers in stock in the moment :" << std::endl;
		for (unsigned int it = 0; it < storage.getStock().size(); it++)
			out << "Number[" << it + 1 << "]: " << storage.getStock()[it] << std::endl;
	}
	if (storage.getStock().size() > 100)
		out << "There is too many numbers to show them." << std::endl;
	return out;
}

/*
	MEMBER FUNCTIONS
*/

const unsigned int &Span::getMaxSize() const { return _maxN; }
const std::vector<int> &Span::getStock() const { return _stock; }

void Span::addNumber(int nb) {
	if (_stock.size() + 1 > _maxN)
		throw MaxElementInStoreException();
	else
		_stock.push_back(nb);
}

long Span::shortestSpan() {
	long	span;
	if (_stock.size() < 2)
		throw NoSpanFoundException();
	else
	{
		span = std::abs(*_stock.begin() - *(_stock.begin() + 1));
		for (std::vector<int>::iterator it1 = _stock.begin(); it1 != _stock.end(); it1++)
		{
			for (std::vector<int>::iterator it2 = it1 + 1; it2 != _stock.end(); it2++)
			{
				if (std::labs(*it1 - *it2) < span)
					span = std::abs(*it1 - *it2);
			}
		}
	}
	return span;
}

long Span::longestSpan() {
	long	span;
	if (_stock.size() < 2)
		throw NoSpanFoundException();
	else
	{
		span = std::abs(*_stock.begin() - *(_stock.begin() + 1));
		for (std::vector<int>::iterator it1 = _stock.begin(); it1 != _stock.end(); it1++)
		{
			for (std::vector<int>::iterator it2 = it1 + 1; it2 != _stock.end(); it2++)
			{
				if (std::abs(*it1 - *it2) > span)
					span = std::abs(*it1 - *it2);
			}
		}
	}
	return span;
}


const char* Span::MaxElementInStoreException::what() const throw() {
	return "\e[1;31mThe number of element in store has attained the maximum possible.\e[0m";
}

const char* Span::NoSpanFoundException::what() const throw() {
	return "\e[1;31mThe number of element in store cannot make a calculation of span possible.\e[0m";
}

void Span::addMoreNumber(std::vector<int>::iterator first, std::vector<int>::iterator last) {
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
}
