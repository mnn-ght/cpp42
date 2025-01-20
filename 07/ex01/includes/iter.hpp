/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:34:28 by magahat           #+#    #+#             */
/*   Updated: 2025/01/20 15:15:24 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <cstdlib>
#include <climits>
#include <float.h>

class Iter
{
	private:
		Iter();
		Iter(const Iter &Iter);
		Iter &operator=(const Iter &other);
	
	public:
		~Iter();
		static void convert(const std::string &s);
};

#endif