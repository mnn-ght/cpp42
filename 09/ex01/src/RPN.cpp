/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:54:30 by magahat           #+#    #+#             */
/*   Updated: 2025/01/26 17:58:28 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"

/*
	CONSTRUCTORS
*/

RPN::RPN(std::string operations) : _numbers() {
	for (size_t i = 0; i < operations.size(); i++)
	{
		if (!isCharacterOk(operations[i]))
			throw InputException();
	}
	std::istringstream istr(operations);
	std::string token;
	istr >> token;
	while (!token.empty())
	{
		_numbers.push_back(token);
		istr >> token;
	}
}

RPN::RPN(void) : _numbers() {
}

RPN::RPN(const RPN &other) {
	*this = other;
}

/*
	DESTRUCTORS
*/

RPN::~RPN() {
}

/*
	OPERATORS OVERLOAD
*/

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
		_numbers = other._numbers;
	return (*this);
}

/*
	MEMBER FUNCTIONS
*/



/*
	EXCEPTIONS DEFINITION
*/

const char* RPN::InputException::what() const throw() {
	return "\e[1;31mError: Characters not acceptable.\e[0m";
}

/*
	OTHER FUNCTIONS
*/

int isCharacterOk(char c) {
	std::string charOk = "+-*/";
	if (isspace(c))
		return true;
	else if (isdigit(c))
		return true;
	else if (charOk.find(c) != std::string::npos)
		return true;
	return false;
}