/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:34:28 by magahat           #+#    #+#             */
/*   Updated: 2025/01/26 12:18:44 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <set>

class RPN
{
private:
	std::set<char> numbers;
	
public:
	RPN();
	RPN(std::string filename);
	RPN(const RPN &other);
	RPN &operator=(const RPN &other);
	
	~RPN() {};
};


#endif