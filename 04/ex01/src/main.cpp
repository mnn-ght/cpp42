/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:54:30 by magahat           #+#    #+#             */
/*   Updated: 2024/12/05 15:16:00 by magahat          ###   ########.fr       */
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
	delete dog;
	delete cat;
	
	return 0;
}