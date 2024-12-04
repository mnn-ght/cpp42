/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:32:55 by magahat           #+#    #+#             */
/*   Updated: 2024/12/02 14:11:19 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"

void	Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level)
{
	std::string		lvl[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void			(Harl::*p[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	int				i = 0;

	while (i < 4 && lvl[i].compare(level) != 0)
		i++;
	if (i > 3)
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	if (i < 4)
		(this->*p[i])();
}

Harl::Harl()
{
	return ;
}

Harl::~Harl()
{
	return ;
}
