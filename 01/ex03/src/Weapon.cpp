/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:07:41 by magahat           #+#    #+#             */
/*   Updated: 2024/11/28 15:10:43 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Weapon.hpp"

Weapon::Weapon(std::string type) : type(type) {
	return ;
}

Weapon::~Weapon()
{
	return ;
}

std::string Weapon::getType()
{
	return this->type;
}

void	Weapon::setType(std::string type)
{
	this->type = type;
	return ;
}
