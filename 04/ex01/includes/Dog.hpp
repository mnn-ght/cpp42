/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:28:43 by magahat           #+#    #+#             */
/*   Updated: 2024/12/05 15:17:49 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain* _brain;

public:
	Dog();
	Dog(const Dog &Dog);
	
	~Dog();

	Dog &operator=(const Dog &Dog);

	void	makeSound() const;
	void	think() const;
};

#endif