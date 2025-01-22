/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:54:30 by magahat           #+#    #+#             */
/*   Updated: 2025/01/22 11:08:00 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Base.hpp"
#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"

int main(void)
{
	/* A child;
	Base *parent = &child;
	B	*child2 = static_cast<B *>(parent);
	
	A	*child3;
	B	*child4 = static_cast<B *>(child3);
	Base *parent2 = child3;
	B	*child5 = static_cast<B *>(parent2); */
	
	Base* ptr;
	ptr = generate();
	identify(ptr);
	identify(*ptr);
	delete (ptr);
	return (0);
}