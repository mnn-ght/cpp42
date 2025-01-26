/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:54:30 by magahat           #+#    #+#             */
/*   Updated: 2025/01/26 12:35:47 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc < 2)
		std::cout << "\e[1;31mError: not enough arguments.\e[0m" << std::endl;
	return 0;
}