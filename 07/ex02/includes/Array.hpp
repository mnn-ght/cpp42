/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:34:28 by magahat           #+#    #+#             */
/*   Updated: 2025/02/05 13:12:44 by magahat          ###   ########.fr       */
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
	Array() : _ar(NULL), _len(0){};
	Array(unsigned int n) : _ar(NULL), _len(n) {
		if (n > 0)
			_ar = new T[n];
	};
	Array(Array const &other) : _ar(NULL), _len(other._len){
		_ar = new T[_len];
		for (unsigned int i = 0; i < _len; i++)
			_ar[i] = other._ar[i];
	};

	Array &operator=(const Array &other) {
		if (_ar != NULL)
			delete[] this->_ar;
		_len = other._len;
		_ar = new T[_len];
		for (unsigned int i = 0; i < _len; i++)
			_ar[i] = other._ar[i];
		return *this;
	};

	T &operator[](const int &index) {
		if (index >= (int)_len || index < 0)
			throw OutOfRangeException();
		return _ar[index];
	};

	class OutOfRangeException : public std::exception {
		const char* what() const throw() { return "\e[1;31mThe asked index is out of range.\e[0m";};
	};

	unsigned int size() const { return _len; };
	
	~Array() {
		if (_ar != NULL)
		{
			delete[] _ar;
			_ar = NULL;
		}
	};
};
#endif