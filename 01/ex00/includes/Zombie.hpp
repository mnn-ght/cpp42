/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:54:43 by magahat           #+#    #+#             */
/*   Updated: 2024/11/28 14:05:52 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie {

public:
	Zombie(std::string name);
	~Zombie();

	void	announce(void);

private:
	std::string name;

};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif
