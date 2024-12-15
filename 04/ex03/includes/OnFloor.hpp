/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OnFloor.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 12:50:56 by magahat           #+#    #+#             */
/*   Updated: 2024/12/15 17:21:08 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ONFLOOR_HPP
#define ONFLOOR_HPP

#include "AMateria.hpp"

class AMateria;

class OnFloor
{
private:
	AMateria *_MatOnFloor[1];
	OnFloor *_next;
	OnFloor *_prev;

public:
	OnFloor();
	OnFloor(AMateria *newMateria);
	OnFloor(const OnFloor &src);

	OnFloor &operator=(const OnFloor &src);
	
	~OnFloor();

	AMateria *getMateria() const;
	OnFloor *getNext() const;

	OnFloor* add_node(AMateria *newMateria);
	OnFloor* go_first_node();
	void delete_nodes();
};

#endif