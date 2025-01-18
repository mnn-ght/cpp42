/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 13:28:09 by magahat           #+#    #+#             */
/*   Updated: 2025/01/18 13:28:10 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../includes/AForm.hpp"

/*
	CONSTRUCTORS
*/

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _isSigned(0), _requiredGradeSign(gradeToSign), _requiredGradeExecute(gradeToExecute) {
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
	else if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
}

AForm::AForm(void) : _name("Manon"), _isSigned(0), _requiredGradeSign(90), _requiredGradeExecute(30) {
}

AForm::AForm(const AForm &other) : _name(""), _isSigned(0), _requiredGradeSign(1), _requiredGradeExecute(1) {
	*this = other;
}

/*
	DESTRUCTORS
*/

AForm::~AForm() {
}

/*
	OPERATORS OVERLOAD
*/

AForm &AForm::operator=(const AForm &other)
{
	(std::string)_name = other._name;
	_isSigned = other._isSigned;
	return (*this);
}

std::ostream	&operator<<(std::ostream& out, const AForm &paper)
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

const std::string	&AForm::getName() const
{
	return _name;
}

const bool	&AForm::getIsSigned() const
{
	return _isSigned;
}

const int	&AForm::getGradeToSign() const
{
	return _requiredGradeSign;
}

const int	&AForm::getGradeToExecute() const
{
	return _requiredGradeExecute;
}

AForm &AForm::beSigned(const Bureaucrat &officer) {
	if (officer.getGrade() > this->_requiredGradeSign)
		throw GradeTooLowException();
	else
	{
		_isSigned = 1;
		std::cout << "\e[1;32m" << officer.getName() << " signed " << this->_name << ".\e[0m" << std::endl;
	}
	return *this;
}

void AForm::execute(const Bureaucrat &executor) const
{
	if (executor.getGrade() > this->_requiredGradeExecute)
		throw GradeTooLowException();
	else
	{
		this->formAction();
		std::cout << "\e[1;32m" << executor.getName() << " executed " << this->_name << ".\e[0m" << std::endl;
	}
}


const char* AForm::GradeTooHighException::what() const throw() {
	return "Grade too high.";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "Grade too low.";
}
