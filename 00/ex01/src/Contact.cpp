/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:51:17 by magahat           #+#    #+#             */
/*   Updated: 2024/12/07 13:59:45 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Contact.hpp"

void put_str(std::string temp)
{
	if (temp.size() > 10)
	{
		temp.resize(9);
		std::cout << temp;
		std::cout << ".";
	}
	else if (temp.size() < 10)
	{
		while (temp.size() < 10)
			temp.insert(0, " ");
		std::cout << temp;
	}
	else
		std::cout << temp;
	std::cout << "|";
}


std::string get_line()
{
	std::string dest;
	
	while (1)
	{
		std::getline(std::cin, dest);
		dest.erase(0, dest.find_first_not_of("\t\v\f\r"));
		while (isspace(dest[dest.length() - 1]))
			dest.erase(dest.find_last_not_of(" \t\v\r\f") + 1, dest[dest.length() - 1]);
		if (dest.empty())
			std::cout << "";
		else
			break ;
	}
	return (dest);
}

void	Contact::print(Contact Contact, int index)
{
	std::cout << "\e[1;94mYou chose to see the information of " << Contact.first_name << std::endl;
	std::cout << "\e[3;94mIndex: " << index + 1 << "," << std::endl;
	std::cout << "First name: " << Contact.first_name << "," << std::endl;
	std::cout << "Last name: " << Contact.last_name << "," << std::endl;
	std::cout << "Nickname: " << Contact.nickname << "," << std::endl;
	std::cout << "Phone number: " << Contact.phone_number << "," << std::endl;
	std::cout << "Darkest secret: " << Contact.secret << ".\e[0m" << std::endl;
	std::cout << std::endl;
}

void	Contact::print_search(Contact *Contact, int index)
{
	std::cout << "\e[34m---------------------------------------------" << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	for(int i = 0; i < index; i++)
	{
		std::cout << "\e[34m|         " << i + 1 << "|";
		put_str(Contact[i].first_name);
		put_str(Contact[i].last_name);
		put_str(Contact[i].nickname);
		std::cout << std::endl;
		std::cout << "---------------------------------------------\e[0m" << std::endl;
	}
	std::cout << std::endl;
}

Contact	Contact::new_contact(void)
{
	Contact New;
	
	std::cout << "\e[35mFirst Name of the contact:\e[0m" << std::endl;
	New.first_name = get_line();
	if (New.first_name == "CANCEL")
		return (New);
	
	std::cout << "\e[35mLast Name of ";
	std::cout << New.first_name << ": \e[0m" << std::endl;
	New.last_name = get_line();
	if (New.last_name == "CANCEL")
		return (New);
	
	std::cout << "\e[35mNickname of ";
	std::cout << New.first_name << ": \e[0m" << std::endl;
	New.nickname = get_line();
	if (New.nickname == "CANCEL")
		return (New);
	
	std::cout << "\e[35mPhone number of ";
	std::cout << New.first_name << ": \e[0m" << std::endl;
	while (1)
	{
		New.phone_number = get_line();
		if (New.phone_number == "CANCEL")
			return (New);
		else
		{
			int	ok = 1;
			for (unsigned i = 0; i < New.phone_number.length(); ++i)
			{
				if (isdigit(New.phone_number.at(i)) == 0)
				{
					std::cout << "\e[31mYou must enter a number for the phone number.\e[0m" << std::endl;
					ok = 0;
					break ;
				}
			}
			if (ok == 1)
				break;
		}
	}
	
	std::cout << "\e[35mDarkest secret of ";
	std::cout << New.first_name << ": \e[0m" << std::endl;
	New.secret = get_line();
	if (New.secret == "CANCEL")
		return (New);
	return (New);
}

int		Contact::check(Contact Contact)
{
	if (Contact.first_name == "CANCEL" || Contact.last_name == "CANCEL" || Contact.nickname == "CANCEL" || Contact.phone_number == "CANCEL" || Contact.secret == "CANCEL")
	{
		std::cout << "\e[31mYou have canceled the addition of a new contact.\e[0m" << std::endl;
		return (0);
	}
	else
		return (1);
}