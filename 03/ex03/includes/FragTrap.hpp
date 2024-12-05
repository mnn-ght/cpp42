/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:28:43 by magahat           #+#    #+#             */
/*   Updated: 2024/12/05 12:58:36 by magahat          ###   ########.fr       */
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
	
	std::string	getName(void);
	int	getHP(void);
	int	getEnergy(void);
	int	getDamage(void);
};

#endif