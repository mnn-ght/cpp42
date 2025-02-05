/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:33:48 by magahat           #+#    #+#             */
/*   Updated: 2024/12/07 13:59:55 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook.hpp"

int main()
{
	PhoneBook 	MyPhone;
	std::string	prompt;
	int			index;

	std::cout << "\e[1;32mWelcome to the crappy/awesome phonebook software: My Phone Book !\e[0m" << std::endl;
	std::cout << std::endl;
	while (1)
	{
		std::cout << "\e[2;32mTo start with My Phone Book, enter: \'ADD\' to add a new contact in your Phone Book. Be careful, You can add only 8 contacts." << std::endl;
		std::cout << "To search contacts in My Phone Book, enter: \'SEARCH\' to search a contact in your Phone Book." << std::endl;
		std::cout << "To exit My Phone Book, enter: \'EXIT\'. Be careful, once you leave, My Phone Book deletes all contact added.\e[0m" << std::endl;
		std::cout << std::endl;
		prompt = get_line();
		if (prompt == "ADD")
		{
			std::cout << "\e[2;35mYou chose the option \'ADD a new contact\' of My Phone Book. You will be asked various element to create a new contact.\e[0m" << std::endl;
			if (MyPhone.NbContact == 8)
			{
				std::cout << "\e[31mYou've already added 8 contacts. If you choose to continue, you will delete the oldest." << std::endl;
				std::cout << "Do you wish to continue ? (YES or NO)\e[0m" << std::endl;
				prompt = get_line();
				if (prompt == "YES")
				{
					MyPhone.Contacts[8] = MyPhone.Contacts[8].new_contact();
					if (MyPhone.Contacts[8].check(MyPhone.Contacts[8]) == 1)
					{
						for(int i = MyPhone.NbContact - 2; i >= 0; i--)
							MyPhone.Contacts[i + 1] = MyPhone.Contacts[i];
						MyPhone.Contacts[0] = MyPhone.Contacts[8];
						std::cout << std::endl;
						std::cout << "\e[1;35mCongrats: you added a new contact.\e[0m" << std::endl;
						std::cout << std::endl;
					}
				}
				else
					std::cout << "\e[31mYou chose to not add a new contact.\e[0m" << std::endl;
			}
			else
			{
				MyPhone.Contacts[8] = MyPhone.Contacts[8].new_contact();
				if (MyPhone.Contacts[8].check(MyPhone.Contacts[8]) == 1)
				{
					for(int i = MyPhone.NbContact - 1; i >= 0; i--)
						MyPhone.Contacts[i + 1] = MyPhone.Contacts[i];
					MyPhone.Contacts[0] = MyPhone.Contacts[8];
					if (MyPhone.NbContact < 8)
						MyPhone.NbContact++;
					std::cout << std::endl;
					std::cout << "\e[1;35mCongrats: you added a new contact.\e[0m" << std::endl;
					std::cout << std::endl;
				}
			}
		}
		else if (prompt == "SEARCH")
		{
			std::cout << "\e[2;34mYou chose the option \'SEARCH for a contact\' of My Phone Book. Please choose the contact you want to display.\e[0m" << std::endl;
			std::cout << std::endl;
			if (MyPhone.NbContact == 0)
			{
				std::cout << "\e[31mThere is no contact to search for: you have no friend.\e[0m" << std::endl;
				std::cout << std::endl;
			}
			else
			{
				MyPhone.Contacts[0].print_search(MyPhone.Contacts, MyPhone.NbContact);
				std::cout << "\e[34mEnter the index of the contact you want to display (\'CANCEL\' to quit search):\e[0m" << std::endl;
			
				while (1)
				{
					prompt = get_line();
					if (prompt == "CANCEL")
						break ;
					index = std::atoi(prompt.c_str()) - 1;
					if (index < MyPhone.NbContact && index >= 0)
					{
						MyPhone.Contacts[index].print(MyPhone.Contacts[index], index);
						break ;
					}
					else
					{
						std::cout << "\e[31mIndex entered is invalid." << std::endl;
						std::cout << "Enter a number between 1 and " << MyPhone.NbContact << ".\e[0m" << std::endl;
					}
				}
			}
		}
		else if (prompt == "EXIT")
		{
			std::cout << "\e[1;32mThank you for using My Phone Book service. We hope to see you again.\e[0m" << std::endl;
			break ;
		}
		else if (prompt == "ADD FAST")
		{
			if (MyPhone.NbContact > 0)
			{
				std::cout << "\e[2;31mYou've already added at least 1 contact. If you choose to continue, you will delete all your contacts." << std::endl;
				std::cout << "Do you wish to continue ? (YES or NO)\e[0m" << std::endl;
				prompt = get_line();
				if (prompt == "YES")
					MyPhone = PhoneBook::add_fast();
			}
			else
				MyPhone = PhoneBook::add_fast();
		}
		else
			std::cout << "\e[31mSorry we didn't recognize \'" << prompt << "\'. Please try these commands: \e[0m" << std::endl;
	}
	return 0;
}