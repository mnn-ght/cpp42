/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:37:09 by magahat           #+#    #+#             */
/*   Updated: 2025/01/19 14:17:28 by magahat          ###   ########.fr       */
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

bool	IsStringConvertible(const std::string &s) {
	std::string charOK = ".-+f";
	bool	point = 0, sign = 0;
	for (size_t i = 0; i < s.length(); i++)
	{
		if (!isdigit(s[i]) && charOK.find(s[i]) == std::string::npos)
		{
			std::cout << "digit pas ok ou find pas ok = " << s[i] << std::endl;
			return 0;
		}
		else if (s[i] == 'f' && i != s.length() - 1)
		{
			std::cout << "F pas ok" << std::endl;
			return 0;
		}
		else if (charOK.find(s[i]) != std::string::npos)
		{
			if (s[i] == '.' && point == 1)
			{
				std::cout << "point pas ok" << std::endl;
				return 0;
			}
			else if (s[i] == '.' && point == 0)
				point = 1;
			else if ((s[i] == '+' || s[i] == '-') && sign == 1)
			{
				std::cout << "sign pas ok" << std::endl;
				return 0;
			}
			else if ((s[i] == '+' || s[i] == '-') && sign == 1)
				sign = 1;				
		}
	}
	return (1);
}

/* bool	IsPrintable(int	n) {
	
} */

void	ScalarConverter::convert(const std::string &s) {
	std::string pseudoLiteralsDouble[3] = {"-inf", "+inf", "nan"};
	std::string pseudoLiteralsFloat[3] = {"-inff", "+inff", "nanf"};
	std::string	toChar;
	int		toInt = 0;
	float	toFloat = 0;
	double	toDouble = 0;
	
	for (size_t i = 0; i < 3; i++)
	{
		if (s == pseudoLiteralsDouble[i] || s == pseudoLiteralsFloat[i])
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: " << pseudoLiteralsFloat[i] << std::endl;
			std::cout << "double: " << pseudoLiteralsDouble[i] << std::endl;
			return ;
		}
	}
	
	if (IsStringConvertible(s))
	{
		toInt = std::atoi(s.c_str());
		if (s[s.length() - 1] == 'f')
		{
			toFloat = std::atof(s.c_str());
			toDouble = static_cast<double>(toFloat);
		}
		else
		{
			toDouble = std::atof(s.c_str());
			toFloat = static_cast<float>(toDouble);
		}
		if (toInt >= 32 && toInt <= 126)
			toChar = static_cast<char>(toInt);
		else
			toChar = "Non displayable";
		std::cout << "char: " << toChar << std::endl;
		std::cout << "int: " << toInt << std::endl;
		if (toFloat - static_cast<int>(toFloat) == 0)
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
	else
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return ;
	}
	
	
}