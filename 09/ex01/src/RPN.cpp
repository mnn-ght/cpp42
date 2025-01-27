/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:54:30 by magahat           #+#    #+#             */
/*   Updated: 2025/01/27 11:16:33 by magahat          ###   ########.fr       */
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
	while (!istr.eof())
	{
		istr >> token;
		if (token.size() == 1)
			_numbers.push_back(token);
		else
		{
			std::list<std::string> tmp = toSplit(token);
			for (std::list<std::string>::iterator i = tmp.begin(); i != tmp.end(); i++)
			{
				if ((*i).size() != 1)
					throw InputNumberException();
				_numbers.push_back(*i);
			}
		}
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

RPN &RPN::setNumbers(std::string &str) {
	if (!_numbers.empty())
		_numbers.clear();
	for (size_t i = 0; i < str.size(); i++)
	{
		if (!isCharacterOk(str[i]))
			throw InputException();
	}
	std::istringstream istr(str);
	std::string token;
	while (!istr.eof())
	{
		istr >> token;
		if (token.size() == 1)
			_numbers.push_back(token);
		else
		{
			std::list<std::string> tmp = toSplit(token);
			for (std::list<std::string>::iterator i = tmp.begin(); i != tmp.end(); i++)
			{
				if ((*i).size() != 1)
					throw InputNumberException();
				_numbers.push_back(*i);
			}
		}
	}
	return *this;
}

void RPN::doCalc() {
	std::stack<int> calc;
	for (std::list<std::string>::iterator it = _numbers.begin(); it != _numbers.end(); it++)
	{
		if (isdigit((*it)[0]))
			calc.push(std::atoi((*it).c_str()));
		else if (calc.size() < 2)
			throw InputFormatException();
		else
		{
			int i = calc.top();
			calc.pop();
			int j = calc.top();
			calc.pop();
			switch ((*it)[0])
			{
			case '+':
				calc.push(j + i);
				break;
			case '-':
				calc.push(j - i);
				break;
			case '*':
				calc.push(j * i);
				break;
			case '/':
				calc.push(j / i);
				break;
			}
		}
	}
	if (calc.size() != 1)
		throw InputFormatException();
	std::cout << calc.top() << std::endl;
}


/*
	EXCEPTIONS DEFINITION
*/

const char* RPN::InputException::what() const throw() {
	return "\e[1;31mError: Characters not acceptable.\e[0m";
}
const char* RPN::InputNumberException::what() const throw() {
	return "\e[1;31mError: Input numbers must be less than 10.\e[0m";
}
const char* RPN::InputFormatException::what() const throw() {
	return "\e[1;31mError: Input format must reverse polish notation.\e[0m";
}

/*
	OTHER FUNCTIONS
*/

int isCharacterOk(char c) {
	std::string charOp = "+-*/";
	if (isspace(c))
		return true;
	else if (isdigit(c))
		return true;
	else if (charOp.find(c) != std::string::npos)
		return true;
	return false;
}

std::list<std::string> toSplit(std::string str) {
	std::list<std::string> splited;
	std::string charOp = "+-*/";
	int nb = -1;
	int l = 0;
	for (size_t i = 0; i < str.size(); i++)
	{
		// std::cout << "str[" << i << "] = " << str[i] << std::endl;
		if (isdigit(str[i]))
		{
			l++;
			if (nb == -1)
				nb = i;
			if (i == str.length() - 1)
				splited.push_back(str.substr(nb, l));
		}
		else if (charOp.find(str[i]) != std::string::npos)
		{
			if (nb >= 0)
			{
				splited.push_back(str.substr(nb, l));
				nb = -1;
				l = 0;
			}
			splited.push_back(str.substr(i, 1));
		}
		// std::cout << "nb == " << nb << std::endl;
		// for (std::list<std::string>::iterator i = splited.begin(); i != splited.end(); i++)
		// 		std::cout << "splited arg = " << *i << std::endl;
	}
	return splited;
}