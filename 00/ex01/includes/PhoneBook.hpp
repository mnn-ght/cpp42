/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 15:35:04 by magahat           #+#    #+#             */
/*   Updated: 2024/11/27 15:42:30 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {

public:
	Contact Contacts[9];
	int		NbContact;

	PhoneBook(void);
	~PhoneBook(void);

	static PhoneBook add_fast(void);
};

#endif