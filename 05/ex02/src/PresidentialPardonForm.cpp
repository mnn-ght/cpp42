/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 13:35:44 by magahat           #+#    #+#             */
/*   Updated: 2025/01/18 13:39:58 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PresidentialPardonForm.hpp"

/*
	CONSTRUCTORS
*/

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PPF", 25, 5), _target(target) {
}

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("PPF", 25, 5), _target("Manon") {
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm("PPF", 25, 5), _target("Manon") {
	*this = other;
}

/*
	DESTRUCTORS
*/

PresidentialPardonForm::~PresidentialPardonForm() {
}

/*
	OPERATORS OVERLOAD
*/

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	this->~PresidentialPardonForm();
	new(this) PresidentialPardonForm(other._target);
	return (*this);
}

std::ostream	&operator<<(std::ostream& out, const PresidentialPardonForm &paper)
{
	out << "The form '" << paper.getName() << "' can be signed by a Bureaucrat grade " << paper.getGradeToSign() << " minimum and can be executed by a Bureaucrat grade " << paper.getGradeToExecute() << " minimum.";
	if (paper.getIsSigned() == 0)
		out << " The form '" << paper.getName() << "' is not signed at the moment." << std::endl;
	else
		out << " The form '" << paper.getName() << "' is already signed." << std::endl;
	return out;
}

/*
	MEMBER FUNCTIONS
*/

const std::string	&PresidentialPardonForm::getTarget() const
{
	return _target;
}

void PresidentialPardonForm::formAction() const
{
	std::cout << _target << " has been pardonned by Zaphod Beeblebrox" << std::endl;
}
