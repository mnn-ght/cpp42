/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:34:28 by magahat           #+#    #+#             */
/*   Updated: 2025/01/22 15:10:38 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <exception>

class NotFoundException : public std::exception {
	const char * what() const throw() { return "No occurence of the target in the container.";};
};

template<typename T>
typename T::iterator easyfind(T& container, int target) {
	for (typename T::iterator i = container.begin(); i != container.end(); ++i)
	{
		if (*i == target)
			return i;
	}
	throw NotFoundException();
};




#endif