/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 15:35:04 by magahat           #+#    #+#             */
/*   Updated: 2024/12/07 14:00:02 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->NbContact = 0;
	return;
}

PhoneBook::~PhoneBook(void)
{
	this->NbContact = 0;
	return;
}

PhoneBook PhoneBook::add_fast(void)
{
	PhoneBook Imaginary_friends;

	Imaginary_friends.NbContact = 8;
	
	Imaginary_friends.Contacts[0].first_name = "Albert";
	Imaginary_friends.Contacts[0].last_name = "Dupont Laporte";
	Imaginary_friends.Contacts[0].nickname = "Albi";
	Imaginary_friends.Contacts[0].phone_number = "06********";
	Imaginary_friends.Contacts[0].secret = "****** *** *****";
	
	Imaginary_friends.Contacts[1].first_name = "Caroline";
	Imaginary_friends.Contacts[1].last_name = "Laporte";
	Imaginary_friends.Contacts[1].nickname = "Caro";
	Imaginary_friends.Contacts[1].phone_number = "06********";
	Imaginary_friends.Contacts[1].secret = "****** *** *****";

	Imaginary_friends.Contacts[2].first_name = "Marie Emmanuelle";
	Imaginary_friends.Contacts[2].last_name = "Laplace";
	Imaginary_friends.Contacts[2].nickname = "Carotte";
	Imaginary_friends.Contacts[2].phone_number = "06********";
	Imaginary_friends.Contacts[2].secret = "****** *** *****";

	Imaginary_friends.Contacts[3].first_name = "Pierre";
	Imaginary_friends.Contacts[3].last_name = "Lefilou";
	Imaginary_friends.Contacts[3].nickname = "Rocher";
	Imaginary_friends.Contacts[3].phone_number = "06********";
	Imaginary_friends.Contacts[3].secret = "****** *** *****";

	Imaginary_friends.Contacts[4].first_name = "Patrick";
	Imaginary_friends.Contacts[4].last_name = "LeBreton";
	Imaginary_friends.Contacts[4].nickname = "BZH";
	Imaginary_friends.Contacts[4].phone_number = "06********";
	Imaginary_friends.Contacts[4].secret = "****** *** *****";

	Imaginary_friends.Contacts[5].first_name = "Oihana";
	Imaginary_friends.Contacts[5].last_name = "Ettcheverry";
	Imaginary_friends.Contacts[5].nickname = "La basque";
	Imaginary_friends.Contacts[5].phone_number = "06********";
	Imaginary_friends.Contacts[5].secret = "****** *** *****";

	Imaginary_friends.Contacts[6].first_name = "Jean Christophe";
	Imaginary_friends.Contacts[6].last_name = "Arnaud";
	Imaginary_friends.Contacts[6].nickname = "kiki";
	Imaginary_friends.Contacts[6].phone_number = "06********";
	Imaginary_friends.Contacts[6].secret = "****** *** *****";

	Imaginary_friends.Contacts[7].first_name = "Florence";
	Imaginary_friends.Contacts[7].last_name = "Bernard";
	Imaginary_friends.Contacts[7].nickname = "Flo";
	Imaginary_friends.Contacts[7].phone_number = "06********";
	Imaginary_friends.Contacts[7].secret = "****** *** *****";
	
	std::cout << "\e[2;35mYou've succesfully created 8 imaginary friends.\e[0m" << std::endl;
	return (Imaginary_friends);
}
