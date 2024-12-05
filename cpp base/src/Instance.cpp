/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Instance.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 09:56:38 by magahat           #+#    #+#             */
/*   Updated: 2024/12/05 10:21:56 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Instance.hpp"

/*
	CONSTRUCTORS
*/

Instance::Instance(std::string base_need) : base_need(base_need)
{
	std::cout << "Instance constructor called !" << std::endl;
}

Instance::Instance(void) : base_need("DEF4ULT")
{
	std::cout << "Default Instance constructor called !" << std::endl;
}

Instance::Instance(const Instance &Instance_name)
{
	std::cout << "Copy Instance constructor called !" << std::endl;
	*this = Instance_name;
}

/*
	DESTRUCTORS
*/

Instance::~Instance()
{
	std::cout << "Instance destructor called !" << std::endl;
}

/*
	OPERATORS OVERLOAD
*/

Instance &Instance::operator=(const Instance &Instance_name)
{
	std::cout << "Copy assignment operator called." << std::endl;
	// if attributes are not const
	if (this != &Instance_name)
		this->base_need = Instance_name.getbase_need();
	return (*this);

	// if attributes are const
	this->~Instance();
	new(this) Instance(Instance_name.base_need);
	return (*this);
}

/*
	MEMBER FUNCTIONS
*/

std::string	Instance::getbase_need() const
{
	return this->base_need;
}


void	Instance::setbase_need(std::string base_need)
{
	// only works if attributes are not const
	this->base_need = base_need;
}
