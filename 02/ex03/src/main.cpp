/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:54:30 by magahat           #+#    #+#             */
/*   Updated: 2024/12/04 15:20:14 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Point.hpp"

int main( void )
{
	Point a(3, 2);
	Point b(7, 10);
	Point c(13, 6);
	Point p(8, 6);
	
	std::cout << "le point est : " << (bsp(a,b,c,p) ? "\e[32mdans le triangle\e[0m" : "\e[31mhors du triangle\e[0m") << std::endl;
	return 0;
}
