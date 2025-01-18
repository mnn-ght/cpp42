/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 09:56:38 by magahat           #+#    #+#             */
/*   Updated: 2024/12/05 10:21:56 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"
#include "../includes/Bureaucrat.hpp"

/*
	CONSTRUCTORS
*/

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _isSigned(0), _requiredGradeSign(gradeToSign), _requiredGradeExecute(gradeToExecute) {
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
	else if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
}

Form::Form(void) : _name("Manon"), _isSigned(0), _requiredGradeSign(90), _requiredGradeExecute(30) {
}

Form::Form(const Form &other) : _name(""), _isSigned(0), _requiredGradeSign(1), _requiredGradeExecute(1)
{
	*this = other;
}


/*
	DESTRUCTORS
*/

Form::~Form() {
}

/*
	OPERATORS OVERLOAD
*/

Form &Form::operator=(const Form &other)
{
	this->~Form();
	new(this) Form(other._name, other._requiredGradeSign, other._requiredGradeExecute);
	return (*this);
}

std::ostream	&operator<<(std::ostream& out, const Form &paper)
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

const std::string	&Form::getName() const
{
	return _name;
}

const bool	&Form::getIsSigned() const
{
	return _isSigned;
}

const int	&Form::getGradeToSign() const
{
	return _requiredGradeSign;
}

const int	&Form::getGradeToExecute() const
{
	return _requiredGradeExecute;
}

Form &Form::beSigned(const Bureaucrat &officer) {
	if (officer.getGrade() > this->_requiredGradeSign)
		throw GradeTooLowException();
	else
	{
		_isSigned = 1;
		std::cout << "\e[3;32m" << officer.getName() << " signed '" << this->_name << "'.\e[0m" << std::endl;
	}
	return *this;
}


const char* Form::GradeTooHighException::what() const throw() {
	return "Grade too high.";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Grade too low.";
}

const char* Form::AlreadySignedException::what() const throw() {
	return "Form already signed.";
}
