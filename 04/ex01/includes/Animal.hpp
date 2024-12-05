/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:28:43 by magahat           #+#    #+#             */
/*   Updated: 2024/12/05 14:28:21 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
protected:
	std::string type;
	
public:
	Animal();
	Animal(const Animal &Animal);
	
	virtual ~Animal();

	Animal &operator=(const Animal &Animal);

	virtual void	makeSound() const;
	
	std::string	getType() const;
};

#endif