/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:54:30 by magahat           #+#    #+#             */
/*   Updated: 2025/01/22 11:22:52 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"
#include "../includes/Data.hpp"


int main(void)
{
	Data* ptr = new(Data);
	ptr->nb = 0;
	ptr->str = "Hello World !";
	std::cout << "\e[2mTest phrase de Data = \e[2;32m" << ptr->str << "\e[0m" << std::endl;
	uintptr_t raw;
	std::cout << "data ptr = \e[1;32m" << ptr << "\e[0m" << std::endl;
	raw = Serializer::serialize(ptr);
	std::cout << "serialize = " << raw << std::endl;
	std::cout << "deserialize = \e[1;32m" << Serializer::deserialize(raw) << "\e[0m" << std::endl;
	std::cout << "\e[2mTest phrase de Data = \e[2;32m" << Serializer::deserialize(raw)->str << "\e[0m" << std::endl;
	delete (ptr);
	
	return (0);
}