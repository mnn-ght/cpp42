/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:28:43 by magahat           #+#    #+#             */
/*   Updated: 2024/12/08 16:00:07 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include "A_Animal.hpp"
#include "Brain.hpp"

class Dog : public A_Animal
{
private:
	Brain* _brain;

public:
	Dog();
	Dog(const Dog &Dog);
	
	~Dog();

	Dog &operator=(const Dog &Dog);

	void	makeSound() const;
	void	think(int index_idea) const;
};

#endif