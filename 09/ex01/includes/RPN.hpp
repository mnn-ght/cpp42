/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:34:28 by magahat           #+#    #+#             */
/*   Updated: 2025/01/26 17:41:04 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <list>
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
	
	~RPN() {};

	class InputException : public std::exception {
		const char* what() const throw();
	};
};


#endif