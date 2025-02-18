/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:06:23 by magahat           #+#    #+#             */
/*   Updated: 2025/02/18 16:20:22 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array() : _ar(NULL), _len(0){};

template <typename T>
Array<T>::Array(unsigned int n) : _ar(NULL), _len(n) {
	if (n > 0)
		_ar = new T[n];
};

template <typename T>
Array<T>::Array(Array const &other) : _ar(NULL), _len(other._len){
	_ar = new T[_len];
	for (unsigned int i = 0; i < _len; i++)
		_ar[i] = other._ar[i];
};

template <typename T>
Array<T> &Array<T>::operator=(const Array &other) {
	if (_ar != NULL)
		delete[] this->_ar;
	_len = other._len;
	_ar = new T[_len];
	for (unsigned int i = 0; i < _len; i++)
		_ar[i] = other._ar[i];
	return *this;
};

template <typename T>
T &Array<T>::operator[](const int &index) {
	if (index >= (int)_len || index < 0)
		throw OutOfRangeException();
	return _ar[index];
};

template <typename T>
T const Array<T>::operator[](const int &index) const{
	if (index >= (int)_len || index < 0)
		throw OutOfRangeException();
	return _ar[index];
};

template <typename T>
const char* Array<T>::OutOfRangeException::what() const throw() {
	return "\e[1;31mThe asked index is out of range.\e[0m";
}

template <typename T>
unsigned int Array<T>::size() const { return _len; };

template <typename T>
Array<T>::~Array() {
	if (_ar != NULL)
	{
		delete[] _ar;
		_ar = NULL;
	}
};