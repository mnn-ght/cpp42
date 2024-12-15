/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:54:30 by magahat           #+#    #+#             */
/*   Updated: 2024/12/15 17:48:48 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Ice.hpp"
#include "../includes/Cure.hpp"
#include "../includes/Character.hpp"
#include "../includes/MateriaSource.hpp"
#include "../includes/Chocolat.hpp"

int main( void )
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Chocolat());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	
	ICharacter* me = new Character("me");
	
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("chocolat");
	me->equip(tmp);
	tmp = src->createMateria("Cure");
	
	ICharacter* bob = new Character("bob");
	
	me->getstatus();
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->unequip(0);
	
	me->getstatus();
	me->use(0, *bob);
	me->unequip(1);
	me->getstatus();
	
	me->unequip(1);

	delete bob;
	delete me;
	delete src;
	
	return 0;
}