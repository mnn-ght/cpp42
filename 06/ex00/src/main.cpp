/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:54:30 by magahat           #+#    #+#             */
/*   Updated: 2025/01/18 16:50:01 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"


int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "\e[1;31mun seul argument apres './convert'.\e[0m" << std::endl;
		return -1;
	}
	std::string s = argv[1];
	ScalarConverter::convert(s);
	return (0);
}