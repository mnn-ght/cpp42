/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:54:30 by magahat           #+#    #+#             */
/*   Updated: 2025/02/23 11:48:57 by magahat          ###   ########.fr       */
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
	std::cout << "\e[2;34m------------- iteration increment -------------\e[0m" << std::endl;
	while (it != ite)
	{
		std::cout << "Number [" << i << "] = " << *it << std::endl;
		++it;
		i++;
	}
	i--;
	MutantStack<int>::reverse_iterator rit = mstack.rbegin();
	MutantStack<int>::reverse_iterator rite = mstack.rend();
	std::cout << "\e[2;34m------------- iteration decrement -------------\e[0m" << std::endl;
	while (rit != rite)
	{
		std::cout << "Number [" << i << "] = " << *rit << std::endl;
		++rit;
		i--;
	}
	std::cout << "top = " << mstack.top() << std::endl;
	std::cout << "size = " << mstack.size() << std::endl;
	std::cout << "\e[1;32m=== TEST STACK ===\e[0m" << std::endl;
	std::stack<int> s(mstack);
	std::cout << "top = " << s.top() << std::endl;
	std::cout << "size = " << s.size() << std::endl;
	std::cout << "We pop the last number("<< s.top() << ")." << std::endl;
	s.pop();
	while (!s.empty())
	{
		std::cout << "new top = " << s.top() << std::endl;
		std::cout << "We pop the last number("<< s.top() << ")." << std::endl;
		s.pop();
	}
	std::cout << "size = " << s.size() << std::endl;

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
	std::cout << "\e[2;34m------------- iteration increment -------------\e[0m" << std::endl;
	while (lit != lite)
	{
		std::cout << "Number [" << j << "] = " << *lit << std::endl;
		++lit;
		j++;
	}
	j--;
	std::list<int>::reverse_iterator rlit = l1.rbegin();
	std::list<int>::reverse_iterator rlite = l1.rend();
	std::cout << "\e[2;34m------------- iteration decrement -------------\e[0m" << std::endl;
	while (rlit != rlite)
	{
		std::cout << "Number [" << j << "] = " << *rlit << std::endl;
		++rlit;
		j--;
	}
	std::cout << "top = " << l1.back() << std::endl;
	return 0;
}