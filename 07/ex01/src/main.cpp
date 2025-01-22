/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:54:30 by magahat           #+#    #+#             */
/*   Updated: 2025/01/22 12:17:52 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/iter.hpp"

int main( void ) {
	int i[5] = {1, 2, 3, 4, 5};
	double	d[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
	float	f[3] = {1.1f, 2.2f, 3.3f};
	char	c[3] = {'a', 'b', 'c'};
	std::string str[3] = {"hello", "world", "!"};
	void	*ptr[3] = {&i, &d, &f};
	
	iter(i, 5, &printT);
	iter(d, 5, &printT);
	iter(f, 3, &printT);
	iter(c, 3, &printT);
	iter(str, 3, &printT);
	iter(ptr, 3, &printT);
}
