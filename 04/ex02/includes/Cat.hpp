/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:28:43 by magahat           #+#    #+#             */
/*   Updated: 2024/12/08 16:00:04 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include "A_Animal.hpp"
#include "Brain.hpp"

class Cat : public A_Animal
{
private:
	Brain* _brain;

public:
	Cat();
	Cat(const Cat &Cat);
	
	~Cat();

	Cat &operator=(const Cat &Cat);

	void	makeSound() const;
	void	think(int index_idea) const;
};

#endif