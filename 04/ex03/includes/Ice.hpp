/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 17:33:22 by magahat           #+#    #+#             */
/*   Updated: 2024/12/14 18:14:32 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice();
		Ice(std::string const &type);
		Ice(const Ice &src);
		
		~Ice();

		Ice &operator=(const Ice &src);

		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif