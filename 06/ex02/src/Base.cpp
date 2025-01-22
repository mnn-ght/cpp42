/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:20:59 by magahat           #+#    #+#             */
/*   Updated: 2025/01/20 11:43:49 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Base.hpp"
#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"
#include "../includes/D.hpp"

Base::~Base() {
}

Base * generate(void) {
	srand(time(NULL));
	int	i = std::rand() % 4;
 	switch (i)
	{
	case 0:
		std::cout << "\e[1;32mA\e[0m created." << std::endl;
		return new(A);
	case 1:
		std::cout << "\e[1;32mB\e[0m created." << std::endl;
		return new(B);
	case 2:
		std::cout << "\e[1;32mC\e[0m created." << std::endl;
		return new(C);
	case 3:
		std::cout << "\e[1;32mD\e[0m created." << std::endl;
		return new(D);
	default:
		return NULL;
	}
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "Result of identify via ptr = \e[1;32mA\e[0m" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Result of identify via ptr = \e[1;32mB\e[0m" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Result of identify via ptr = \e[1;32mC\e[0m" << std::endl;
	else
		std::cout << "\e[1;31mERROR : not recognized via ptr.\e[0m" << std::endl;
}

void identify(Base& p) {
	try {
		(void)dynamic_cast<A &>(p);
		std::cout << "Result of identify via ref = \e[1;32mA\e[0m" << std::endl;
	}
	catch (std::exception &e)
	{
		try {
			(void)dynamic_cast<B &>(p);
			std::cout << "Result of identify via ref = \e[1;32mB\e[0m" << std::endl;
		}
		catch (std::exception &e)
		{
			try {
				(void)dynamic_cast<C &>(p);
				std::cout << "Result of identify via ref = \e[1;32mC\e[0m" << std::endl;
			}
			catch (std::exception &e)
			{
				std::cout << "\e[1;31mERROR : not recognized via ref -> " << e.what() << ".\e[0m" << std::endl;
			}
		}
	}
}

