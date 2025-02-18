/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:54:30 by magahat           #+#    #+#             */
/*   Updated: 2025/02/18 16:04:50 by magahat          ###   ########.fr       */
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
	iter(i, 5, printT<int>);
	std::cout << "\e[3;32m--------- Iter increment int --------\e[0m" << std::endl;
	iter(i, 5, incrementT<int>);
	std::cout << "\e[3;32m--------- Iter print int --------\e[0m" << std::endl;
	iter(i, 5, printT<int>);
	std::cout << "\e[3;32m--------- Iter decrement int --------\e[0m" << std::endl;
	iter(i, 5, decrementT<int>);
	std::cout << "\e[3;32m--------- Iter print int --------\e[0m" << std::endl;
	iter(i, 5, printT<int>);
	std::cout << "\e[1;32m==================== DOUBLE ====================\e[0m" << std::endl;
	std::cout << "\e[3;32m--------- Iter print double --------\e[0m" << std::endl;
	iter(d, 5, printT<double>);
	std::cout << "\e[3;32m--------- Iter increment double --------\e[0m" << std::endl;
	iter(d, 5, incrementT<double>);
	std::cout << "\e[3;32m--------- Iter print double --------\e[0m" << std::endl;
	iter(d, 5, printT<double>);
	std::cout << "\e[3;32m--------- Iter decrement double --------\e[0m" << std::endl;
	iter(d, 5, decrementT<double>);
	std::cout << "\e[3;32m--------- Iter print double --------\e[0m" << std::endl;
	iter(d, 5, printT<double>);
	std::cout << "\e[1;32m==================== FLOAT ====================\e[0m" << std::endl;
	std::cout << "\e[3;32m--------- Iter print float --------\e[0m" << std::endl;
	iter(f, 3, printT<float>);
	std::cout << "\e[1;32m==================== CHAR ====================\e[0m" << std::endl;
	std::cout << "\e[3;32m--------- Iter print char --------\e[0m" << std::endl;
	iter(c, 3, printT<char>);
	std::cout << "\e[3;32m--------- Iter increment char --------\e[0m" << std::endl;
	iter(c, 3, incrementT<char>);
	std::cout << "\e[3;32m--------- Iter print char --------\e[0m" << std::endl;
	iter(c, 3, printT<char>);
	std::cout << "\e[3;32m--------- Iter decrement char --------\e[0m" << std::endl;
	iter(c, 3, decrementT<char>);
	std::cout << "\e[3;32m--------- Iter print char --------\e[0m" << std::endl;
	iter(c, 3, printT<char>);
	std::cout << "\e[1;32m==================== STRING ====================\e[0m" << std::endl;
	std::cout << "\e[3;32m--------- Iter print string --------\e[0m" << std::endl;
	iter(str, 3, printT<std::string>);
	std::cout << "\e[1;32m==================== PTR ====================\e[0m" << std::endl;
	std::cout << "\e[3;32m--------- Iter print ptr --------\e[0m" << std::endl;
	iter(ptr, 3, printT<void *>);

	return 0;
}

/* class Awesome
{
  public:
    Awesome( void ) : _n( 42 ) { return; }
    int get( void ) const { return this->_n; }
  private:
    int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
{
  o << rhs.get();
  return o;
}

template< typename T >
void print( T& x )
{
  std::cout << x << std::endl;
  return;
}

int main() {
  int tab[] = { 0, 1, 2, 3, 4 };
  Awesome tab2[5];

  iter( tab, 5, print<const int> );
  iter( tab2, 5, print<Awesome> );

  return 0;
} */