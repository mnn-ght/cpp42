/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:54:30 by magahat           #+#    #+#             */
/*   Updated: 2025/01/20 12:45:50 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Base.hpp"

int main(void)
{
	Base* ptr;
	ptr = generate();
	identify(ptr);
	identify(*ptr);
	delete (ptr);
	return (0);
}