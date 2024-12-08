/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:54:30 by magahat           #+#    #+#             */
/*   Updated: 2024/12/08 16:40:21 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include "../includes/WrongCat.hpp"

int main( void )
{
	const A_Animal* j = new Dog();
	const A_Animal* i = new Cat();
	// const A_Animal* meta = new A_Animal();
	
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	
	delete j;//should not create a leak
	delete i;

	Dog	*dog = new Dog();
	Cat	*cat = new Cat();

	Cat *copy_cat(cat);
	
	std::cout << copy_cat->getType() << std::endl;
	copy_cat->think(42);
	delete dog;
	delete cat;
	
	return 0;
}