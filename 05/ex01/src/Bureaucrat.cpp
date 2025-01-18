/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 09:56:38 by magahat           #+#    #+#             */
/*   Updated: 2024/12/05 10:21:56 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"

/*
	CONSTRUCTORS
*/

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade){
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
}

Bureaucrat::Bureaucrat(void) : _name("Manon"), _grade(10) {
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) {
	*this = other;
}

/*
	DESTRUCTORS
*/

Bureaucrat::~Bureaucrat() {
}

/*
	OPERATORS OVERLOAD
*/

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	this->~Bureaucrat();
	new(this) Bureaucrat(other._name, other._grade);
	return (*this);
}

std::ostream	&operator<<(std::ostream& out, const Bureaucrat &officer)
{
	out << officer.getName() << ", bureaucrat grade " << officer.getGrade() << "." << std::endl;
	return out;
}

/*
	MEMBER FUNCTIONS
*/

const std::string	&Bureaucrat::getName() const
{
	return _name;
}

const int	&Bureaucrat::getGrade() const
{
	return _grade;
}

Bureaucrat &Bureaucrat::incrementGrade() {
	if (_grade - 1 < 1)
		throw GradeTooHighException();
	else
		_grade--;
	return *this;
}

Bureaucrat &Bureaucrat::decrementGrade() {
	if (_grade + 1 > 150)
		throw GradeTooLowException();
	else
		_grade++;
	return *this;
}

Bureaucrat &Bureaucrat::signForm(Form &paper) {
	try {
		if (paper.getIsSigned() == 1)
			throw Form::AlreadySignedException();
		else
			paper.beSigned(*this);
	}
	catch (Form::AlreadySignedException) {
		std::cerr << "\e[1;31m" << this->_name << " couldn't sign '" << paper.getName() << "' because the form is already signed." << "\e[0m" << std::endl;
	}
	catch (Form::GradeTooLowException) {
		std::cerr << "\e[1;31m" << this->_name << " couldn't sign '" << paper.getName() << "' because its grade was too low." << "\e[0m" << std::endl;
	}
	return *this;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade cannot go higher than 1.";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade cannot go lower than 150.";
}


