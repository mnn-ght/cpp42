/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:06:16 by magahat           #+#    #+#             */
/*   Updated: 2024/11/28 14:51:57 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
	Zombie	*zombieHorde = new Zombie[N];

	for(int i = 0; i < N; i++)
	{
		zombieHorde[i].addName(name);
	}
	if (N == Zombie::nbZombie)
		std::cout << "Your zombie horde is complete and ready to deploy !" << std::endl;
	return (zombieHorde);
}
