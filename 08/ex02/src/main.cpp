/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:54:30 by magahat           #+#    #+#             */
/*   Updated: 2025/01/26 10:53:33 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MutantStack.hpp"
#include <list>

int main()
{
	std::cout << "\e[1;32m=== TEST MUTANTSTACK ===\e[0m" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "top = " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "size = " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	int i = 0;
	while (it != ite)
	{
		std::cout << "Number [" << i << "] = " << *it << std::endl;
		++it;
		i++;
	}
	std::cout << "top = " << mstack.top() << std::endl;
	std::stack<int> s(mstack);

	std::cout << "\e[1;32m=== TEST LIST ===\e[0m" << std::endl;
	std::list<int> l1;
	l1.push_back(5);
	l1.push_back(17);
	std::cout << "top = " << l1.back() << std::endl;
	l1.pop_back();
	std::cout << "size = " << l1.size() << std::endl;
	l1.push_back(3);
	l1.push_back(5);
	l1.push_back(737);
	l1.push_back(0);
	std::list<int>::iterator lit = l1.begin();
	std::list<int>::iterator lite = l1.end();
	++lit;
	--lit;
	int j = 0;
	while (lit != lite)
	{
		std::cout << "Number [" << j << "] = " << *lit << std::endl;
		++lit;
		j++;
	}
	std::cout << "top = " << l1.back() << std::endl;
	return 0;
}