/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:54:43 by magahat           #+#    #+#             */
/*   Updated: 2024/11/28 14:24:37 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <stdlib.h>
#include <new>

class Zombie {

public:
	Zombie();
	~Zombie();

	void	announce(void);
	void	addName(std::string name);
	
	static int	nbZombie;

private:
	std::string name;

};

Zombie *zombieHorde(int N, std::string name);

#endif
