/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:54:30 by magahat           #+#    #+#             */
/*   Updated: 2024/12/02 10:03:46 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HumanA.hpp"
#include "../includes/HumanB.hpp"

int	main(void)
{
	{
		std::cout << "Test 1 :" << std::endl;
		Weapon club = Weapon("crude spiked club");
			
		HumanA Agatha("Agatha", club);
		Agatha.attack();
		club.setType("some other type of club");
		Agatha.attack();
		std::cout << std::endl;
	}
	{
		std::cout << "Test 2 :" << std::endl;
		Weapon club = Weapon("crude spiked club");
		
		HumanB Billy("Billy");
		Billy.setWeapon(club);
		Billy.attack();
		club.setType("some other type of club");
		Billy.attack();
		std::cout << std::endl;
	}
	{
		std::cout << "Test 3 : (B attacks the first time without setting a weapon)" << std::endl;
		Weapon club = Weapon("crude spiked club");
		
		HumanB Billy("Billy");
		Billy.attack();
		Billy.setWeapon(club);
		Billy.attack();
		club.setType("some other type of club");
		Billy.attack();
		std::cout << std::endl;
	}
return 0;
}
