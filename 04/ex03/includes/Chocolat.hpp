/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Chocolat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 17:33:22 by magahat           #+#    #+#             */
/*   Updated: 2024/12/14 18:14:32 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHOCOLAT_HPP
#define CHOCOLAT_HPP

#include "AMateria.hpp"

class Chocolat : public AMateria
{
	public:
		Chocolat();
		Chocolat(std::string const &type);
		Chocolat(const Chocolat &src);
		
		~Chocolat();

		Chocolat &operator=(const Chocolat &src);

		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif