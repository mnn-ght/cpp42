/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:34:28 by magahat           #+#    #+#             */
/*   Updated: 2025/02/18 16:20:17 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>
#include <sstream>

template<typename T>
class Array
{
private:
	T *_ar;
	unsigned int _len;
	
public:
	Array();
	Array(unsigned int n);
	Array(Array const &other);

	Array &operator=(const Array &other);

	T &operator[](const int &index);
	T const operator[](const int &index) const;

	class OutOfRangeException: public std::exception {
		public:
			const char* what() const throw();
	};


	unsigned int size() const;
	
	~Array();
};

#include "Array.tpp"
#endif