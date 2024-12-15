/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 15:05:45 by magahat           #+#    #+#             */
/*   Updated: 2024/12/15 17:18:20 by magahat          ###   ########.fr       */
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
	/* AMateria *_onFloor[100];
	int	_NbFloor; */
	OnFloor* _OnFloor;
	int	_NbOnFloor;

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
	void getstatus() const;
};

std::ostream	&operator<<(std::ostream& out, const ICharacter &character);

#endif