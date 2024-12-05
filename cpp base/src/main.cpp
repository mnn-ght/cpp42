/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:54:30 by magahat           #+#    #+#             */
/*   Updated: 2024/12/05 10:22:57 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Instance.hpp"

int main( void )
{
	std::cout << std::endl;
	
	Instance	Instance_name("NO_NAME");
	std::cout << "Instance name is " << Instance_name.getbase_need() << "." << std::endl;
	
	std::cout << std::endl;
	
	Instance	Instance_copy(Instance_name);
	std::cout << "Instance_copy name is " << Instance_copy.getbase_need() << "." << std::endl;
	
	std::cout << std::endl;
	
	Instance	Instance_default;
	std::cout << "Instance_default name is " << Instance_default.getbase_need() << "." << std::endl;
	
	std::cout << std::endl;
	
	Instance_default = Instance_name;
	std::cout << "Instance_default name is " << Instance_default.getbase_need() << "." << std::endl;
	
	std::cout << std::endl;
	
	Instance_name.setbase_need("Manon");
	std::cout << "Instance name is " << Instance_name.getbase_need() << "." << std::endl;
	
	std::cout << std::endl;
	
	return (0);
}