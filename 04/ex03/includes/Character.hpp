/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 15:05:45 by magahat           #+#    #+#             */
/*   Updated: 2024/12/14 18:41:54 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter
{
private:
	std::string _name;
	AMateria *_inventory[4];
	AMateria *_onFloor[100];
	int	_NbFloor;

public:
	Character();
	Character(std::string name);
	Character(const Character &src);
	~Character();

	Character &operator=(const Character &src);

	std::string const & getName() const;
	
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
};

std::ostream	&operator<<(std::ostream& out, const ICharacter &character);

#endif