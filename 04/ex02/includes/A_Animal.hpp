/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A_Animal.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:28:43 by magahat           #+#    #+#             */
/*   Updated: 2024/12/08 15:59:57 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class A_Animal
{
protected:
	std::string type;
	
public:
	A_Animal();
	A_Animal(const A_Animal &Animal);
	
	virtual ~A_Animal();

	A_Animal &operator=(const A_Animal &Animal);

	virtual void	makeSound() const = 0;
	
	std::string	getType() const;
};

#endif