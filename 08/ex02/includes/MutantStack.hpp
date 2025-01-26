/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:34:28 by magahat           #+#    #+#             */
/*   Updated: 2025/01/26 10:42:52 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <iterator>

template<typename T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack() : std::stack<T>() {};
	MutantStack(const MutantStack &other) : std::stack<T>(other) {};
	~MutantStack() {};
	MutantStack &operator=(const MutantStack &other) {
		if (this != &other)
			std::stack<T>::operator=(other);
		return *this;
	};
	
	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
	typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
	
	iterator begin() { return std::stack<T>::c.begin(); };
	iterator end() { return std::stack<T>::c.end(); };
	const_iterator begin() const { return std::stack<T>::c.begin(); };
	const_iterator end() const { return std::stack<T>::c.end(); };
	reverse_iterator rbegin() { return std::stack<T>::c.rbegin(); };
	reverse_iterator rend() { return std::stack<T>::c.rend(); };
	const_reverse_iterator rbegin() const { return std::stack<T>::c.rbegin(); };
	const_reverse_iterator rend() const { return std::stack<T>::c.rend(); };
};


#endif