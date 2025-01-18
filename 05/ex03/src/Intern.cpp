/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 15:19:23 by magahat           #+#    #+#             */
/*   Updated: 2025/01/18 16:03:13 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"

std::string Intern::knownFormNature[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};

Intern::Intern() {
}

Intern::Intern(const Intern &other)
{
	*this = other;
}

Intern::~Intern() {
}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	return *this;
}

AForm* Intern::makeForm(std::string type, std::string target) {
	AForm *form;
	int n = 3;
	for (int i = 0; i < 3; i++)
		n = (type == Intern::knownFormNature[i] ? i : n);
	switch (n) {
		case 0:
			form = new PresidentialPardonForm(target);
			break;
		case 1:
			form = new RobotomyRequestForm(target);
			break;
		case 2:
			form = new ShrubberyCreationForm(target);
			break;
		default:
			throw Intern::UnrecognizedFormException();
			return NULL;
	}
	std::cout << "Intern creates " << type << std::endl;
	return form;
}

const char* Intern::UnrecognizedFormException::what() const throw() {
	return "The nature of the form requested is not recognized.";
}
