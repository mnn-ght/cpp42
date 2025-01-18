/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 12:05:17 by magahat           #+#    #+#             */
/*   Updated: 2025/01/18 13:38:52 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ShrubberyCreationForm.hpp"

/*
	CONSTRUCTORS
*/

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("SCF", 145, 137), _target(target) {
}

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("SCF", 145, 137), _target("Home") {
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm("SCF", 145, 137), _target("Home") {
	*this = other;
}

/*
	DESTRUCTORS
*/

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

/*
	OPERATORS OVERLOAD
*/

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	this->~ShrubberyCreationForm();
	new(this) ShrubberyCreationForm(other._target);
	return (*this);
}

std::ostream	&operator<<(std::ostream& out, const ShrubberyCreationForm &paper)
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

const std::string	&ShrubberyCreationForm::getTarget() const
{
	return _target;
}

void ShrubberyCreationForm::formAction() const
{
	std::fstream fs_out;
	std::string filename;
	
	filename = _target;
	fs_out.open(filename.append("_shrubbery").c_str(), std::fstream::out);
	if (!(fs_out.is_open()))
	{
		std::cout << "\e[1;31mError" << std::endl;
		std::cout << "Could not open the new file.\e[0m" << std::endl;
	}
	fs_out << "				* *    " << std::endl;
	fs_out << " 		 *    *  *" << std::endl;
	fs_out << " 	  *  *    *     *  *" << std::endl;
	fs_out << " 	*     *    *  *    *" << std::endl;
	fs_out << " * *   *    *    *    *   *" << std::endl;
	fs_out << "*     *  *    * * .#  *   *" << std::endl;
	fs_out << " *   *     * #.  .# *   *" << std::endl;
	fs_out << "   *     '#.  #: #' * *    *" << std::endl;
	fs_out << " *   * * '#. ##'       *" << std::endl;
	fs_out << "	  *       '###" << std::endl;
	fs_out << " 			'##" << std::endl;
	fs_out << " 			##." << std::endl;
	fs_out << " 			.##:" << std::endl;
	fs_out << " 			:###" << std::endl;
	fs_out << " 			;###" << std::endl;
	fs_out << " 			,####." << std::endl;
	fs_out << "_|_|_|_|_|_.######._|_|_|_|_|" << std::endl;
	fs_out.close();
}
