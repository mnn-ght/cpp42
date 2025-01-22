/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:34:28 by magahat           #+#    #+#             */
/*   Updated: 2025/01/22 15:25:51 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <exception>

template<typename T>
class Span
{
private:
	unsigned int N;
public:
	Span(unsigned int n);
	Span();
	Span(const Span &other);

	Span &operator=(const Span &other);

	~Span();
	
	void addNumber();
	int &shortestSpan() const;
	int &longestSpan() const;
};



#endif