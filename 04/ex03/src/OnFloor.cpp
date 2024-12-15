/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OnFloor.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 13:49:27 by magahat           #+#    #+#             */
/*   Updated: 2024/12/15 17:21:13 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/OnFloor.hpp"


OnFloor::OnFloor()
{
	this->_MatOnFloor[0] = NULL;
	this->_next = NULL;
	this->_prev = NULL;
}

OnFloor::OnFloor(AMateria *newMateria)
{
	this->_MatOnFloor[0] = newMateria;
	this->_next = NULL;
	this->_prev = NULL;
}

OnFloor::OnFloor(const OnFloor &src)
{
	*this = src;
}

OnFloor &OnFloor::operator=(const OnFloor &src)
{
	this->delete_nodes();
	new(this) OnFloor(src._MatOnFloor[0]);
	this->_next = src._next;
	this->_prev = src._prev;
	return *this;
}

OnFloor::~OnFloor()
{
	delete this->_MatOnFloor[0];
}

OnFloor* OnFloor::add_node(AMateria *newMateria)
{
	OnFloor *tmp = new OnFloor(newMateria);

	tmp->_prev = this;
	this->_next = tmp;
	return tmp;
}

OnFloor* OnFloor::go_first_node()
{
	OnFloor *tmp;

	tmp = this;
	while (tmp->_prev != NULL)
		tmp = tmp->_prev;
	return tmp;
}

void OnFloor::delete_nodes()
{
	OnFloor *tmp;
	OnFloor *tmp2;
	
	tmp = this->go_first_node();
	while (tmp)
	{
		tmp2 = tmp->_next;
		delete tmp;
		tmp = tmp2;
	}
	delete tmp;
}

AMateria *OnFloor::getMateria() const
{
	return this->_MatOnFloor[0];
}

OnFloor *OnFloor::getNext() const
{
	return this->_next;
}