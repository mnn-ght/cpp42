/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:28:43 by magahat           #+#    #+#             */
/*   Updated: 2024/12/11 15:37:40 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(const ScavTrap &scavtrap);

		ScavTrap(std::string name);
		~ScavTrap();

		ScavTrap	&operator=(const ScavTrap &scavtrap);

		void attack(const std::string& target);
		void guardGate( void );

	private:
		bool	gatekeeper;
};

std::ostream	&operator<<(std::ostream& out, const ScavTrap &scavtrap);

#endif