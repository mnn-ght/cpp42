/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 13:28:03 by magahat           #+#    #+#             */
/*   Updated: 2025/01/18 13:28:04 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef AFORM_HPP
#define AFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	std::string const _name;
	bool	_isSigned;
	int const	_requiredGradeSign;
	int const	_requiredGradeExecute;
	
public:
	AForm();
	AForm(const AForm &other);
	
	AForm(std::string name, int gradeToSign, int gradeToExecute);
	virtual ~AForm();

	AForm &operator=(const AForm &other);

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

	AForm &beSigned(const Bureaucrat &officer);
	void execute(const Bureaucrat &executor) const;
	virtual void formAction() const = 0;
};

std::ostream	&operator<<(std::ostream& out, const AForm &AForm);

#endif