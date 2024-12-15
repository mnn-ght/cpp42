/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:49:01 by magahat           #+#    #+#             */
/*   Updated: 2024/12/15 17:42:45 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		this->_memory[i] = NULL;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_memory[i])
			delete this->_memory[i];
	}
}

void MateriaSource::learnMateria(AMateria* m)
{
	int j = 0;
	for (int i = 0; i < 4; i++)
	{
		if (!this->_memory[i])
		{
			this->_memory[i] = m;
			j = 1;
			break;
		}
	}
	if (j == 0)
	{
		std::cout << "\e[31mThis MateriaSource can't learn new Materias. It has already learned 4 Materias.\e[0m" << std::endl;
		delete m;
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_memory[i])
		{
			if (this->_memory[i]->getType() == type)
				return this->_memory[i]->clone();
		}
	}
	std::cout << "\e[31mThis MateriaSource can't create the Materia because it didn't learn the type asked.\e[0m" << std::endl;
	return (0);
}
