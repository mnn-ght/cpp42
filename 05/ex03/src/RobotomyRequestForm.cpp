/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 13:27:50 by magahat           #+#    #+#             */
/*   Updated: 2025/01/18 13:38:20 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RobotomyRequestForm.hpp"

int RobotomyRequestForm::nbRobotomy = 0;

/*
	CONSTRUCTORS
*/

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RRF", 72, 45), _target(target) {
}

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RRF", 72, 45), _target("Manon") {
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm("RRF", 72, 45), _target("Manon") {
	*this = other;
}

/*
	DESTRUCTORS
*/

RobotomyRequestForm::~RobotomyRequestForm() {
}

/*
	OPERATORS OVERLOAD
*/

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	this->~RobotomyRequestForm();
	new(this) RobotomyRequestForm(other._target);
	return (*this);
}

std::ostream	&operator<<(std::ostream& out, const RobotomyRequestForm &paper)
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

const std::string	&RobotomyRequestForm::getTarget() const
{
	return _target;
}

void RobotomyRequestForm::formAction() const
{
	RobotomyRequestForm::nbRobotomy += 1;
	std::cout << "*Makes some drilling noises*" << std::endl;
	if (RobotomyRequestForm::nbRobotomy % 2 == 0)
		std::cout << _target << " has been robotomized successfully." << std::endl;
	else
		std::cout << "The robotomy on " << _target << " failed." << std::endl;
}
