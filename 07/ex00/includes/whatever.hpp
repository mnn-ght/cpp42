/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:34:28 by magahat           #+#    #+#             */
/*   Updated: 2025/01/20 15:15:28 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>
#include <cstdlib>
#include <climits>
#include <float.h>

class Whatever
{
	private:
		Whatever();
		Whatever(const Whatever &Whatever);
		Whatever &operator=(const Whatever &other);
	
	public:
		~Whatever();
		static void convert(const std::string &s);
};

#endif