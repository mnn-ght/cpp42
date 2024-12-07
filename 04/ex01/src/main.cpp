/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:54:30 by magahat           #+#    #+#             */
/*   Updated: 2024/12/07 14:22:31 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include "../includes/WrongCat.hpp"

int main( void )
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	delete j;//should not create a leak
	delete i;

	Animal	*ar[10];
		
	for (int i = 0; i < 5; i++)
		ar[i] = new Dog();
	for (int i = 5; i < 10; i++)
		ar[i] = new Cat();
	for (int i = 0; i < 10; i++)
		delete ar[i];

	Dog	*dog = new Dog();
	Cat	*cat = new Cat();

	Cat *copy_cat(cat);
	
	std::cout << copy_cat->getType() << std::endl;
	copy_cat->think(42);
	delete dog;
	delete cat;
	
	return 0;
}