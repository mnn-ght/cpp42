/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:54:30 by magahat           #+#    #+#             */
/*   Updated: 2025/01/15 14:20:16 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

int main( void )
{
	std::cout << "\e[1;32m=========== Test instanciate normal ===========\e[0m" << std::endl;
	try {
		Bureaucrat	officer("Manon", 2);
		std::cout << officer << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		std::cerr << "\e[1;31mGrade too high : TooHighException.\e[0m" << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e) {
		std::cerr << "\e[1;31mGrade too low : TooLowException.\e[0m" << std::endl;
	}
	std::cout << std::endl;

	
	std::cout << "\e[1;32m=========== Test instanciate too high (grade = 0) ===========\e[0m" << std::endl;
	try {
		Bureaucrat	officer("Manon", 0);
		std::cout << officer << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		std::cerr << "\e[1;31mGrade too high : TooHighException.\e[0m" << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e) {
		std::cerr << "\e[1;31mGrade too low : TooLowException.\e[0m" << std::endl;
	}
	std::cout << std::endl;


	std::cout << "\e[1;32m=========== Test instanciate too low (grade = 190) ===========\e[0m" << std::endl;
	try {
		Bureaucrat	officer("Manon", 190);
		std::cout << officer << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		std::cerr << "\e[1;31mGrade too high : TooHighException.\e[0m" << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e) {
		std::cerr << "\e[1;31mGrade too low : TooLowException.\e[0m" << std::endl;
	}
	std::cout << std::endl;
	
	std::cout << "\e[1;32m=========== Test increment too high (grade = 1 & try increment) ===========\e[0m" << std::endl;
	try {
		Bureaucrat	officer("Delphine", 2);
		std::cout << officer << std::endl;
		officer.decrementGrade(); // grade should be 3
		std::cout << officer << std::endl;
		officer.incrementGrade().incrementGrade(); // grade should be 1
		std::cout << officer << std::endl;
		officer.incrementGrade(); // trying to incremente 1 : should throw exception Too High
		std::cout << officer << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		std::cerr << "\e[1;31mGrade too high : TooHighException.\e[0m" << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e) {
		std::cerr << "\e[1;31mGrade too low : TooLowException.\e[0m" << std::endl;
	}
	std::cout << std::endl;

	
	std::cout << "\e[1;32m=========== Test decrement too low (grade = 150 & try decrement) ===========\e[0m" << std::endl;
	try {
		Bureaucrat	officer("Guillaume", 150);
		std::cout << officer << std::endl;
		officer.incrementGrade(); // grade should be 149
		std::cout << officer << std::endl;
		officer.decrementGrade().decrementGrade(); // trying to incremente 149 + incremente 150 : should throw exception Too Low
		std::cout << officer << std::endl;
		officer.incrementGrade(); // already exception thrown : what does it do 
		std::cout << officer << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		std::cerr << "\e[1;31mGrade too high : TooHighException.\e[0m" << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e) {
		std::cerr << "\e[1;31mGrade too low : TooLowException.\e[0m" << std::endl;
	}
	
	
	return (0);
}