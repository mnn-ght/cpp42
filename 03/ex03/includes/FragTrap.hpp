/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:28:43 by magahat           #+#    #+#             */
/*   Updated: 2024/12/11 15:48:47 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap: public virtual ClapTrap
{
public:
	FragTrap();
	FragTrap(const FragTrap &FragTrap);

	FragTrap(std::string name);
	~FragTrap();

	FragTrap	&operator=(const FragTrap &FragTrap);

	void highFivesGuys(void);
	
	int	getHP(void);
	int	getEnergy(void);
	int	getDamage(void);
};

std::ostream	&operator<<(std::ostream& out, const FragTrap &fragTrap);

#endif