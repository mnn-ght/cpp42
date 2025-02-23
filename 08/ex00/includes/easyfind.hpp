/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:34:28 by magahat           #+#    #+#             */
/*   Updated: 2025/02/23 11:29:59 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <exception>
#include <algorithm>

class NotFoundException : public std::exception {
	const char * what() const throw() { return "\e[1;31mNo occurence of the target in the container.\e[0m";};
};

template<typename T>
typename T::iterator easyfind(T& container, int target) {
	std::cout << "\e[2;32mTrying to find " << target << " in the container : \t\e[0m";
	typename T::iterator iter = std::find(container.begin(), container.end(), target);
	if (iter != container.end())
		return iter;
	throw NotFoundException();
};




#endif