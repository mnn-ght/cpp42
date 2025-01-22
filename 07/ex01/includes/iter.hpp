/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:34:28 by magahat           #+#    #+#             */
/*   Updated: 2025/01/22 12:16:36 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template< typename T>
void	iter(T* ar, size_t len, void (*fct)(const T &)) {
	std::cout << "--------- Iter ---------" << std::endl;
	for (size_t i = 0; i < len; i++)
		fct(ar[i]);
	
};

template< typename T>
void printT(const T &element) {
	std::cout << element << std::endl;
}

#endif