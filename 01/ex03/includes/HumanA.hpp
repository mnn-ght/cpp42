/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:54:43 by magahat           #+#    #+#             */
/*   Updated: 2024/12/02 09:46:36 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iostream>
#include "../includes/Weapon.hpp"

class HumanA {

public:
	HumanA(std::string name, Weapon &weapon);
	~HumanA();
	void	attack(void);

private:
	std::string name;
	Weapon		&weapon;

};

#endif
