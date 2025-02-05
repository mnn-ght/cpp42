/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:54:30 by magahat           #+#    #+#             */
/*   Updated: 2025/02/05 10:27:13 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/iter.hpp"

template< typename T>
void printT(T &element) {
	std::cout << element << std::endl;
}

template< typename T>
void incrementT(T &element) {
	element ++;
}

template< typename T>
void decrementT(T &element) {
	element --;
}

int main( void ) {
	int i[5] = {1, 2, 3, 4, 5};
	double	d[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
	float	f[3] = {1.1f, 2.2f, 3.3f};
	char	c[3] = {'a', 'b', 'c'};
	std::string str[3] = {"hello", "world", "!"};
	void	*ptr[3] = {&i, &d, &f};
	
	std::cout << "\e[1;32m==================== INT ====================\e[0m" << std::endl;
	std::cout << "\e[3;32m--------- Iter print int --------\e[0m" << std::endl;
	iter(i, 5, &printT);
	std::cout << "\e[3;32m--------- Iter increment int --------\e[0m" << std::endl;
	iter(i, 5, &incrementT);
	std::cout << "\e[3;32m--------- Iter print int --------\e[0m" << std::endl;
	iter(i, 5, &printT);
	std::cout << "\e[3;32m--------- Iter decrement int --------\e[0m" << std::endl;
	iter(i, 5, &decrementT);
	std::cout << "\e[3;32m--------- Iter print int --------\e[0m" << std::endl;
	iter(i, 5, &printT);
	std::cout << "\e[1;32m==================== DOUBLE ====================\e[0m" << std::endl;
	std::cout << "\e[3;32m--------- Iter print double --------\e[0m" << std::endl;
	iter(d, 5, &printT);
	std::cout << "\e[3;32m--------- Iter increment double --------\e[0m" << std::endl;
	iter(d, 5, &incrementT);
	std::cout << "\e[3;32m--------- Iter print double --------\e[0m" << std::endl;
	iter(d, 5, &printT);
	std::cout << "\e[3;32m--------- Iter decrement double --------\e[0m" << std::endl;
	iter(d, 5, &decrementT);
	std::cout << "\e[3;32m--------- Iter print double --------\e[0m" << std::endl;
	iter(d, 5, &printT);
	std::cout << "\e[1;32m==================== FLOAT ====================\e[0m" << std::endl;
	std::cout << "\e[3;32m--------- Iter print float --------\e[0m" << std::endl;
	iter(f, 3, &printT);
	std::cout << "\e[1;32m==================== CHAR ====================\e[0m" << std::endl;
	std::cout << "\e[3;32m--------- Iter print char --------\e[0m" << std::endl;
	iter(c, 3, &printT);
	std::cout << "\e[3;32m--------- Iter increment char --------\e[0m" << std::endl;
	iter(c, 3, &incrementT);
	std::cout << "\e[3;32m--------- Iter print char --------\e[0m" << std::endl;
	iter(c, 3, &printT);
	std::cout << "\e[3;32m--------- Iter decrement char --------\e[0m" << std::endl;
	iter(c, 3, &decrementT);
	std::cout << "\e[3;32m--------- Iter print char --------\e[0m" << std::endl;
	iter(c, 3, &printT);
	std::cout << "\e[1;32m==================== STRING ====================\e[0m" << std::endl;
	std::cout << "\e[3;32m--------- Iter print string --------\e[0m" << std::endl;
	iter(str, 3, &printT);
	std::cout << "\e[1;32m==================== PTR ====================\e[0m" << std::endl;
	std::cout << "\e[3;32m--------- Iter print ptr --------\e[0m" << std::endl;
	iter(ptr, 3, &printT);

	return 0;
}
