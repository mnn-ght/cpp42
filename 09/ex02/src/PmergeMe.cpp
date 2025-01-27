/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:54:30 by magahat           #+#    #+#             */
/*   Updated: 2025/01/27 12:17:30 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

/*
	CONSTRUCTORS
*/

PmergeMe::PmergeMe(int nbElements, char **input) : _nbElements(nbElements), _vct(), _dq() {
	if (nbElements < 1)
		throw InputErrorException();
	if (!parseNumbers(input))
		throw InputErrorException();
	std::cout << "Before:";
	for (std::vector<int>::iterator i = _vct.begin(); i != _vct.end(); i++)
	{
		std::cout << " " << *i;
	}
	std::cout << std::endl;	
}

PmergeMe::PmergeMe(void){}

PmergeMe::PmergeMe(const PmergeMe &other) {
	*this = other;
}

/*
	DESTRUCTORS
*/

PmergeMe::~PmergeMe() {
}

/*
	OPERATORS OVERLOAD
*/

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		_vct = other._vct;
		_dq = other._dq;
	}
	return (*this);
}

/*
	MEMBER FUNCTIONS
*/

bool PmergeMe::parseNumbers(char **input) {
	char *str_end;
	for (size_t i = 1; input[i]; i++)
	{
		long nb = std::strtol(input[i], &str_end, 10);
		if (nb < 0 || nb > INT_MAX || str_end[0] != 0)
			return false;
		_vct.push_back(static_cast<int>(nb));
		_dq.push_back(static_cast<int>(nb));
	}
	if (_vct.size() != _nbElements || _dq.size() != _nbElements)
		return false;
	return true;
}


/*
	EXCEPTIONS DEFINITION
*/

const char* PmergeMe::InputErrorException::what() const throw() {
	return "\e[1;31mError: input not accepted.\e[0m";
}

/*
	OTHER FUNCTIONS
*/

