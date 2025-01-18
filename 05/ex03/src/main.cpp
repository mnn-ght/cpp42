/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:54:30 by magahat           #+#    #+#             */
/*   Updated: 2025/01/18 16:15:44 by magahat          ###   ########.fr       */
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

	return (0);
}