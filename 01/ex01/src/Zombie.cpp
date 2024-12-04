/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:54:38 by magahat           #+#    #+#             */
/*   Updated: 2024/11/28 14:51:50 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

int	Zombie::nbZombie = 0;

void	Zombie::addName(std::string name)
{
	this->name = name;
	return ;
}

void	Zombie::announce()
{
	std::cout << Zombie::name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	return ;
}

Zombie::Zombie()
{
	Zombie::nbZombie += 1;
	std::cout << "Zombie number " << Zombie::nbZombie << " was created ! :)" << std::endl;
	return ;
}

Zombie::~Zombie()
{
	std::cout << "Zombie number " << Zombie::nbZombie << " was destroyed ! :(" << std::endl;
	Zombie::nbZombie -= 1;
	if (Zombie::nbZombie == 0)
		std::cout << "Your zombie horde is completely destroyed !" << std::endl;
	return ;
}