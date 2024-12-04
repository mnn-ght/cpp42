/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:54:43 by magahat           #+#    #+#             */
/*   Updated: 2024/11/28 14:59:41 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon {

public:
	Weapon(std::string type);
	~Weapon();

	std::string	getType(void);
	void		setType(std::string newType);

private:
	std::string	type;	

};

#endif
