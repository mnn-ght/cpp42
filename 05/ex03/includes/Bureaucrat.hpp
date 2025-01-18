/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:48:01 by magahat           #+#    #+#             */
/*   Updated: 2025/01/18 12:05:56 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
private:
	std::string const _name;
	int	_grade;
	
public:
	Bureaucrat();
	Bureaucrat(const Bureaucrat &Bureaucrat);
	
	Bureaucrat(std::string name, int grade);
	~Bureaucrat();

	Bureaucrat &operator=(const Bureaucrat &other);

	class GradeTooHighException: public std::exception {
		public:
			const char* what() const throw();
	};

	class GradeTooLowException: public std::exception {
		public:
			const char* what() const throw();
	};

	const std::string	&getName() const;
	const int	&getGrade() const;

	Bureaucrat &incrementGrade();
	Bureaucrat &decrementGrade();
	
	Bureaucrat &signForm(AForm &paper);
	Bureaucrat &executeForm(const AForm &form);
};

std::ostream	&operator<<(std::ostream& out, const Bureaucrat &bureaucrat);

#endif