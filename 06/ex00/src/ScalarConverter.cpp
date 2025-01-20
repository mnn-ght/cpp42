/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:37:09 by magahat           #+#    #+#             */
/*   Updated: 2025/01/20 14:58:31 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

/*
	CONSTRUCTORS
*/

ScalarConverter::ScalarConverter() {
}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
	*this = other;
}

/*
	DESTRUCTORS
*/

ScalarConverter::~ScalarConverter() {
}

/*
	OPERATORS OVERLOAD
*/

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return *this;
}

bool isPritable(long long n)
{
	if (n >= 32 && n <= 126)
		return true;
	return false;
}

bool isPossible(long long n)
{
	if (n < -128 || n > 127)
		return false;
	return true;
}

bool isDigit(int n)
{
	if (n >= 48 && n <= 57)
		return true;
	return false;
}

std::string	typeString(const std::string &s) {
	std::string charOK = ".-+f";
	bool	point = 0, sign = 0;

	if (s.length() == 1 && !isDigit(s[0]))
		return "char";
	
	for (size_t i = 0; i < s.length(); i++)
	{
		if (!isDigit(s[i]) && charOK.find(s[i]) == std::string::npos) // character pas accept&
			return "false";
		else if (charOK.find(s[i]) != std::string::npos)
		{
			if ((s[i] == '+' || s[i] == '-') && sign == 0 && i == 0)
				sign = 1;
			else if (s[i] == '.' && point == 0 && i != 0 && i != s.length() - 1)
			{
				point = 1;
				if (!isDigit(s[i + 1]))
					return "false";
			}
			else if (s[i] == 'f' && (i == s.length() - 1 && point == 1))
				break ;
			else
				return "false";
		}
	}
	
	if (point == 1)
	{
		if (s[s.length() - 1] == 'f')
			return "float";
		else
			return "double";
	}
	else
	{
		if ((static_cast<long long>(std::atof(s.c_str())) > INT_MAX || static_cast<long long>(std::atof(s.c_str())) < INT_MIN))
			return "int overflow";
		return "int";
	}
}

void	printFromChar(char c)
{
	std::cout << "char : " << c << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void	printFromInt(int i)
{
	if (isPritable(i))
		std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
	else if (isPossible(i))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: impossible" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
}

void	printFromFloat(float f)
{
	if (isPritable(static_cast<long long>(f)))
		std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
	else if (isPossible(static_cast<long long>(f)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: impossible" << std::endl;
	if (static_cast<long long>(f) > INT_MAX || static_cast<long long>(f) < INT_MIN)
		std::cout << "int : impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(f) << std::endl;
	if (f - static_cast<int>(f) == 0)
	{
		std::cout << "float: " << f << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(f) << ".0" << std::endl;
	}
	else
	{
		std::cout << "float: " << f << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(f) << std::endl;
	}
}

void	printFromDouble(double d)
{
	if (isPritable(static_cast<long long>(d)))
		std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
	else if (isPossible(static_cast<long long>(d)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: impossible" << std::endl;
	if (static_cast<long long>(d) > INT_MAX || static_cast<long long>(d) < INT_MIN)
		std::cout << "int : impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	if (d - static_cast<int>(d) == 0)
	{
		std::cout << "float: " << static_cast<float>(d) << ".0f" << std::endl;
		std::cout << "double: " << d << ".0" << std::endl;
	}
	else
	{
		std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
		std::cout << "double: " << d << std::endl;
	}
}

void	ScalarConverter::convert(const std::string &s) {
	std::string	type = "find type";
	/* char	toChar = 0;
	int		toInt = 0;
	float	toFloat = 0;
	double	toDouble = 0; */
	std::string pseudoLiteralsFloat[4] = {"-inff", "+inff", "nanf", "inff"};
	std::string pseudoLiteralsDouble[4] = {"-inf", "+inf", "nan", "inf"};
	
	for (size_t i = 0; i < 4; i++) {
		if (s == pseudoLiteralsDouble[i])
			type = "double";
		else if (s == pseudoLiteralsFloat[i])
			type = "float";
	}
	
	if (type == "find type")
		type = typeString(s);
	
	if (type == "char") {
		printFromChar(static_cast<char>(s[0]));
		/* toChar = static_cast<char>(s[0]);
		toInt = static_cast<int>(toChar);
		toFloat = static_cast<float>(toChar);
		toDouble = static_cast<double>(toChar); */
	}
	else if (type == "int") {
		printFromInt(std::atoi(s.c_str()));

		/* toInt = std::atoi(s.c_str());
		if (isPritable(toChar))
			std::cout << "char: '" << toChar << "'" << std::endl;
		else if (isPossible(toChar))
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: impossible" << std::endl;
		toChar = static_cast<char>(toInt);
		toFloat = static_cast<float>(toInt);
		toDouble = static_cast<double>(toInt); */
	}
	else if (type == "float") {
		printFromFloat(std::atof(s.c_str()));
		/* toFloat = std::atof(s.c_str());
		toChar = static_cast<char>(toFloat);
		toInt = static_cast<int>(toFloat);
		toDouble = static_cast<double>(toFloat);
		checkIntLimit = static_cast<long long>(toFloat); */
	}
	else if (type == "double") {
		printFromDouble(std::atof(s.c_str()));
		/* toDouble = std::atof(s.c_str());
		toChar = static_cast<char>(toDouble);
		toInt = static_cast<int>(toDouble);
		toFloat = static_cast<float>(toDouble);
		checkIntLimit = static_cast<long long>(toDouble); */
	}
	else if (type == "int overflow") {
		std::cout << "String represent a number outside of limits : " << type << "." << std::endl;
		return ;
	}
	else if (type == "false") {
		std::cout << "No type can be recognizes from the string: error syntax." << std::endl;
		return ;
	}
	
	/* if (isPritable(toChar))
		std::cout << "char: '" << toChar << "'" << std::endl;
	else if (isPossible(toChar))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: impossible" << std::endl;
	if ((type == "float" || type == "double") && (checkIntLimit > INT_MAX || checkIntLimit < INT_MIN))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << toInt << std::endl;
	if (toFloat - toInt == 0)
	{
		std::cout << "float: " << toFloat << ".0f" << std::endl;
		std::cout << "double: " << toDouble << ".0" << std::endl;
	}
	else
	{
		std::cout << "float: " << toFloat << "f" << std::endl;
		std::cout << "double: " << toDouble << std::endl;
	} */
}