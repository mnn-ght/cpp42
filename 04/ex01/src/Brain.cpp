/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:47:17 by magahat           #+#    #+#             */
/*   Updated: 2024/12/05 15:17:00 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Brain.hpp"

Brain::Brain()
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = "Ramdom ideas";
	std::cout << "Brain class constructor called." << std::endl;
}

Brain::Brain(const Brain &brain)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = brain.ideas[i];
	std::cout << "Brain copy class constructor called." << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain class destructor called." << std::endl;
}

Brain	&Brain::operator=(const Brain &brain)
{
	if (this != &brain)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = brain.ideas[i];
	}
	return *this;
}