/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:37:09 by magahat           #+#    #+#             */
/*   Updated: 2025/01/20 10:20:18 by magahat          ###   ########.fr       */
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

std::string	typeString(const std::string &s) {
	std::string charOK = ".-+f";
	bool	point = 0, sign = 0;

	if (s.length() == 1 && !isdigit(s[0]))
		return "char";
	
	for (size_t i = 0; i < s.length(); i++)
	{
		if (!isdigit(s[i]) && charOK.find(s[i]) == std::string::npos) // character pas accept&
			return "false";
		else if (charOK.find(s[i]) != std::string::npos)
		{
			if ((s[i] == '+' || s[i] == '-') && sign == 0 && i == 0)
				sign = 1;
			else if (s[i] == '.' && point == 0 && i != 0 && i != s.length() - 1)
				point = 1;
			else if (s[i] == 'f' && (i != s.length() - 1 || point == 0)) // f trouv& dans la chaine de character pas a la fin et sans point
				return "false";
			else if (s[i] == '.' && (point == 1 || i == 0 || i == s.length() - 1)) // 2 points ou 1er character
				return "false";
			else if ((s[i] == '+' || s[i] == '-') && (sign == 1 || i != 0))
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
		return "int";
}

bool isPritable(int n)
{
	if (n >= 32 && n <= 126)
		return true;
	return false;
}

void	ScalarConverter::convert(const std::string &s) {
	std::string	type;
	char	toChar;
	int		toInt;
	float	toFloat;
	double	toDouble;
	std::string pseudoLiteralsFloat[4] = {"-inff", "+inff", "nanf", "inff"};
	std::string pseudoLiteralsDouble[4] = {"-inf", "+inf", "nan", "inf"};
	std::string plusSign = "";
	
	for (size_t i = 0; i < 4; i++)
	{
		if (i == 3)
			plusSign = "+";
		if (s == pseudoLiteralsDouble[i])
		{
			toDouble = std::atof(s.c_str());
			toFloat = static_cast<float>(toDouble);
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: " << plusSign << toFloat << "f" << std::endl;
			std::cout << "double: " << plusSign << toDouble << std::endl;
			return ;
		}
		else if (s == pseudoLiteralsFloat[i])
		{
			toFloat = std::atof(s.c_str());
			toDouble = static_cast<double>(toFloat);
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: " << toFloat << "f" << std::endl;
			std::cout << "double: " << toDouble << std::endl;
			return ;
		}
	}
	
	type = typeString(s);
	if (type == "char")
	{
		toChar = static_cast<char>(s[0]);
		toInt = static_cast<int>(toChar);
		toFloat = static_cast<float>(toChar);
		toDouble = static_cast<double>(toChar);
	}
	else if (type == "int")
	{
		toInt = std::atoi(s.c_str());
		toChar = static_cast<char>(toInt);
		toFloat = static_cast<float>(toInt);
		toDouble = static_cast<double>(toInt);
	}
	else if (type == "float")
	{
		toFloat = std::atof(s.c_str());
		toChar = static_cast<char>(toFloat);
		toInt = static_cast<int>(toFloat);
		toDouble = static_cast<double>(toFloat);
	}
	else if (type == "double")
	{
		toDouble = std::atof(s.c_str());
		toChar = static_cast<char>(toDouble);
		toInt = static_cast<int>(toDouble);
		toFloat = static_cast<float>(toDouble);
	}
	else
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return ;
	}
	
	if (isPritable(toInt))
		std::cout << "char: '" << toChar << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
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
	}
}