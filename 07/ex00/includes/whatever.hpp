/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:34:28 by magahat           #+#    #+#             */
/*   Updated: 2025/01/22 11:51:51 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template< typename T >
void	swap(T &x, T &y) {
	T tmp = x;
	x = y;
	y = tmp;
	return ;
}

template< typename T >
T	const &max(T const &x, T const &y) {
	return (x >= y ? x : y);
}

template< typename T >
T	const &min(T const &x, T const &y) {
	return (x >= y ? y : x);
}

#endif