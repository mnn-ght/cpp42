/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:34:28 by magahat           #+#    #+#             */
/*   Updated: 2025/01/27 10:59:27 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <list>
#include <stack>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <sstream>

class RPN
{
private:
	std::list<std::string> _numbers;
	
public:
	RPN();
	RPN(std::string operations);
	RPN(const RPN &other);
	RPN &operator=(const RPN &other);

	RPN &setNumbers(std::string &str);
	void doCalc();
	
	~RPN();

	class InputException : public std::exception {
		const char* what() const throw();
	};
	class InputNumberException : public std::exception {
		const char* what() const throw();
	};
	class InputFormatException : public std::exception {
		const char* what() const throw();
	};
};

int isCharacterOk(char c);
std::list<std::string> toSplit(std::string str);

#endif