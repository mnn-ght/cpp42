/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:47:37 by magahat           #+#    #+#             */
/*   Updated: 2024/11/25 15:28:03 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <istream>
#include <string>
#include <iomanip>
#include <stdlib.h>

class Contact
{
	public:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	secret;
	
	void	print(Contact Contact, int index);
	void	print_search(Contact *Contact, int index);
	Contact	new_contact(void);
	int		check(Contact Contact);
};

std::string get_line(void);

#endif