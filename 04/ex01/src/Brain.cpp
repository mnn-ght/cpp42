/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:47:17 by magahat           #+#    #+#             */
/*   Updated: 2024/12/07 14:20:56 by magahat          ###   ########.fr       */
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

std::string	*Brain::get_brain()
{
	return this->ideas;
}

std::string	Brain::get_idea(int index_idea)
{
	if (index_idea < 100 && index_idea >= 0)
		return (this->ideas[index_idea]);
	else
		return ("no thoughts.");
}