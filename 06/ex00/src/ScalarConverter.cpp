/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:37:09 by magahat           #+#    #+#             */
/*   Updated: 2025/01/18 16:51:40 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../includes/ScalarConverter.hpp"

/*
	CONSTRUCTORS
*/

ScalarConverter::ScalarConverter() {
}

ScalarConverter::ScalarConverter(void) {
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
	this->~ScalarConverter();
	new(this) ScalarConverter();
	return (*this);
}

void ScalarConverter::convert(const std::string &s) {
	
	std::cout << "char: " << "info" << std::endl;
	std::cout << "int: " << "info" << std::endl;
	std::cout << "float: " << "info" << std::endl;
	std::cout << "double: " << "info" << std::endl;
}