/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:54:30 by magahat           #+#    #+#             */
/*   Updated: 2025/01/15 16:27:42 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"

int main( void )
{
	std::cout << "\e[1;32m=========== Test instanciate normal ===========\e[0m" << std::endl;
	try {
		Bureaucrat	officer("Manon", 2);
		Form	paper("Laisser passer A38", 58, 23);
		std::cout << officer << std::endl;
		std::cout << paper << std::endl;
		officer.signForm(paper);
		std::cout << paper << std::endl;
	}
	catch (Form::GradeTooHighException &e) {
		std::cerr << "\e[1;31mGrade too high : TooHighException.\e[0m" << std::endl;
	}
	catch (Form::GradeTooLowException &e) {
		std::cerr << "\e[1;31mGrade too low : TooLowException.\e[0m" << std::endl;
	}
	std::cout << std::endl;

	
	std::cout << "\e[1;32m=========== Test instanciate too high (grade = 0) ===========\e[0m" << std::endl;
	try {
		Bureaucrat	officer("Manon", 1);
		Form	paper("Laisser passer A38", 0, 0);
		std::cout << officer << std::endl;
		std::cout << paper << std::endl;
		officer.signForm(paper);
	}
	catch (Form::GradeTooHighException &e) {
		std::cerr << "\e[1;31mGrade too high : TooHighException.\e[0m" << std::endl;
	}
	catch (Form::GradeTooLowException &e) {
		std::cerr << "\e[1;31mGrade too low : TooLowException.\e[0m" << std::endl;
	}
	std::cout << std::endl;


	std::cout << "\e[1;32m=========== Test instanciate too low (grade = 190) ===========\e[0m" << std::endl;
	try {
		Bureaucrat	officer("Manon", 1);
		Form	paper("Laisser passer A38", 190, 30);
		std::cout << officer << std::endl;
		std::cout << paper << std::endl;
		officer.signForm(paper);
	}
	catch (Form::GradeTooHighException &e) {
		std::cerr << "\e[1;31mGrade too high : TooHighException.\e[0m" << std::endl;
	}
	catch (Form::GradeTooLowException &e) {
		std::cerr << "\e[1;31mGrade too low : TooLowException.\e[0m" << std::endl;
	}
	std::cout << std::endl;
	
	std::cout << "\e[1;32m=========== Test grade officer too low (grade = 100 & form requirement = 58) ===========\e[0m" << std::endl;
	try {
		Bureaucrat	officer("Manon", 100);
		Form	paper("Laisser passer A38", 58, 23);
		std::cout << officer << std::endl;
		std::cout << paper << std::endl;
		officer.signForm(paper);
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		std::cerr << "\e[1;31mGrade too high : TooHighException.\e[0m" << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e) {
		std::cerr << "\e[1;31mGrade too low : TooLowException.\e[0m" << std::endl;
	}
	std::cout << std::endl;

	std::cout << "\e[1;32m=========== Test try sign twice ===========\e[0m" << std::endl;
	try {
		Bureaucrat	officer("Manon", 2);
		Form	paper("Laisser passer A38", 58, 23);
		std::cout << officer << std::endl;
		std::cout << paper << std::endl;
		officer.signForm(paper);
		std::cout << paper << std::endl;
		officer.signForm(paper);
		std::cout << paper << std::endl;
	}
	catch (Form::GradeTooHighException &e) {
		std::cerr << "\e[1;31mGrade too high : TooHighException.\e[0m" << std::endl;
	}
	catch (Form::GradeTooLowException &e) {
		std::cerr << "\e[1;31mGrade too low : TooLowException.\e[0m" << std::endl;
	}
	std::cout << std::endl;

	return (0);
}