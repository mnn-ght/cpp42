/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:54:30 by magahat           #+#    #+#             */
/*   Updated: 2025/01/20 11:50:00 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"
#include "../includes/Data.hpp"


int main(void)
{
	Data* ptr = new(Data);
	ptr->nb = 0;
	ptr->str = "Hello World !";
	uintptr_t raw;
	std::cout << "data ptr = \e[1;32m" << ptr << "\e[0m" << std::endl;
	raw = Serializer::serialize(ptr);
	std::cout << "serialize = " << raw << std::endl;
	std::cout << "deserialize = \e[1;32m" << Serializer::deserialize(raw) << "\e[0m" << std::endl;
	delete (ptr);
	
	return (0);
}