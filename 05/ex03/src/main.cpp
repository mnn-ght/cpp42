/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:54:30 by magahat           #+#    #+#             */
/*   Updated: 2025/01/18 16:05:37 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/Intern.hpp"

int main( void )
{
	std::cout << "\e[1;32m=========== Test normal ===========\e[0m" << std::endl;
	try {
		Bureaucrat	executer("Manon", 1);
		Intern slave;
		AForm *form;

		form = slave.makeForm("robotomy request", "New intern");
		executer.signForm(*form);
		executer.executeForm(*form);
		delete form;
		form = slave.makeForm("presidential pardon", "New intern");
		executer.signForm(*form);
		executer.executeForm(*form);
		delete form;
		form = slave.makeForm("shrubbery creation", "New intern");
		executer.signForm(*form);
		executer.executeForm(*form);
		delete form;
	}
	catch (Intern::UnrecognizedFormException &e) {
		std::cerr << "\e[1;31m" << e.what() << "\e[0m" << std::endl;
	}
	std::cout << std::endl;

	std::cout << "\e[1;32m=========== Test form non reconnu ===========\e[0m" << std::endl;
	try {
		Bureaucrat	executer("Manon", 1);
		Intern slave;
		AForm *form;

		form = slave.makeForm("random request", "New intern");
		executer.signForm(*form);
		executer.executeForm(*form);
	}
	catch (Intern::UnrecognizedFormException &e) {
		std::cerr << "\e[1;31m" << e.what() << "\e[0m" << std::endl;
	}
	std::cout << std::endl;

	/* 
	std::cout << "\e[1;32m=========== Test execute avant signer ===========\e[0m" << std::endl;
	try {
		Bureaucrat	officer("Manon", 1);
		ShrubberyCreationForm	paper("Home");
		std::cout << officer << std::endl;
		std::cout << paper << std::endl;
		officer.executeForm(paper);
	}
	catch (AForm::GradeTooHighException &e) {
		std::cerr << "\e[1;31mGrade too high : TooHighException.\e[0m" << std::endl;
	}
	catch (AForm::GradeTooLowException &e) {
		std::cerr << "\e[1;31mGrade too low : TooLowException.\e[0m" << std::endl;
	}
	std::cout << std::endl;


	std::cout << "\e[1;32m=========== Test too low to sign ===========\e[0m" << std::endl;
	try {
		Bureaucrat	officer("Manon", 150);
		ShrubberyCreationForm	paper("Home");
		std::cout << officer << std::endl;
		std::cout << paper << std::endl;
		officer.signForm(paper);
		officer.executeForm(paper);
	}
	catch (AForm::GradeTooHighException &e) {
		std::cerr << "\e[1;31mGrade too high : TooHighException.\e[0m" << std::endl;
	}
	catch (AForm::GradeTooLowException &e) {
		std::cerr << "\e[1;31mGrade too low : TooLowException.\e[0m" << std::endl;
	}
	std::cout << std::endl;
	
	std::cout << "\e[1;32m=========== Test too low to execute ===========\e[0m" << std::endl;
	try {
		Bureaucrat	officer("Manon", 144);
		ShrubberyCreationForm	paper("Home");
		std::cout << officer << std::endl;
		std::cout << paper << std::endl;
		officer.signForm(paper);
		officer.executeForm(paper);
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		std::cerr << "\e[1;31mGrade too high : TooHighException.\e[0m" << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e) {
		std::cerr << "\e[1;31mGrade too low : TooLowException.\e[0m" << std::endl;
	}
	std::cout << std::endl; */

	return (0);
}