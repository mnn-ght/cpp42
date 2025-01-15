/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:48:01 by magahat           #+#    #+#             */
/*   Updated: 2025/01/15 13:53:22 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	std::string const _name;
	bool	_isSigned;
	int const	_requiredGradeSign;
	int const	_requiredGradeExecute;
	
public:
	Form();
	// Form(const Form &other);
	
	Form(std::string name, int gradeToSign, int gradeToExecute);
	~Form();

	Form &operator=(const Form &other);

	class GradeTooHighException: public std::exception {
		public:
			const char* what() const throw();
	};

	class GradeTooLowException: public std::exception {
		public:
			const char* what() const throw();
	};

	const std::string	&getName() const;
	const bool	&getIsSigned() const;
	const int	&getGradeToSign() const;
	const int	&getGradeToExecute() const;

	Form &beSigned(const Bureaucrat &officer);
};

std::ostream	&operator<<(std::ostream& out, const Form &Form);

#endif