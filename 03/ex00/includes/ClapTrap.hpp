/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:28:43 by magahat           #+#    #+#             */
/*   Updated: 2024/12/11 15:37:56 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	private:
		std::string const _name;
		int	_HP;
		int	_Energy;
		int	_Damage;
		
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(std::string name, int HP, int Energy, int Damage);
		ClapTrap(const ClapTrap &claptrap);
		
		~ClapTrap();

		ClapTrap &operator=(const ClapTrap &claptrap);

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		std::string	getName(void) const;
};

std::ostream	&operator<<(std::ostream& out, const ClapTrap &claptrap);

#endif