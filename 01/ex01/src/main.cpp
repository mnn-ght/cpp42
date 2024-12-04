/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:54:30 by magahat           #+#    #+#             */
/*   Updated: 2024/11/28 14:51:47 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

void	lauchHorde(int N, std::string name)
{
	Zombie	*zombie_Horde;

	zombie_Horde = zombieHorde(N, name);
	for(int i = 0; i < N; i++)
		zombie_Horde[i].announce();
	delete[] zombie_Horde;
	return ;
}

int	main(int argc, char **argv)
{
	int	N;
	std::string name;

	if (argc != 3)
	{
		std::cout << "You must enter a number and a name as parameters after the program name." << std::endl;
		std::cout << "Example: ./program 12 Didier" << std::endl;
		return (-1);
	}
	N = std::atoi(argv[1]);
	if (N <= 0)
	{
		std::cout << "You must enter a valid number" << std::endl;
		return (-1);
	}
	name = argv[2];
	lauchHorde(N, name);
	
	return (0);
}
