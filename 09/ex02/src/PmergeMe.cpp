/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:54:30 by magahat           #+#    #+#             */
/*   Updated: 2025/01/28 15:47:52 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

/*
	CONSTRUCTORS
*/

PmergeMe::PmergeMe(int nbElements, char **input) : _nbElements(nbElements), _vct(), _dq() {
	if (nbElements < 1)
		throw InputErrorException();
	if (!parseNumbers(input))
		throw InputErrorException();
	std::cout << "Before:";
	for (std::vector<int>::iterator i = _vct.begin(); i != _vct.end(); i++)
		std::cout << " " << *i;
	std::cout << std::endl;	
}

PmergeMe::PmergeMe(void){}

PmergeMe::PmergeMe(const PmergeMe &other) {
	*this = other;
}

/*
	DESTRUCTORS
*/

PmergeMe::~PmergeMe() {
}

/*
	OPERATORS OVERLOAD
*/

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		_vct = other._vct;
		_dq = other._dq;
	}
	return (*this);
}

/*
	MEMBER FUNCTIONS
*/

bool PmergeMe::parseNumbers(char **input) {
	char *str_end;
	for (size_t i = 1; input[i]; i++)
	{
		long nb = std::strtol(input[i], &str_end, 10);
		if (nb < 0 || nb > INT_MAX || str_end[0] != 0)
			return false;
		_vct.push_back(static_cast<int>(nb));
		_dq.push_back(static_cast<int>(nb));
	}
	if (_vct.size() != _nbElements || _dq.size() != _nbElements)
		return false;
	return true;
}

template<class Cit>
void mergeInsertSort(Cit first, Cit last)
{
	if (last - first == 1)
	{
		if (*last < *first)
			std::iter_swap(first, last);
	}
	else
	{
		Cit middle = first + ((last - first) / 2);
		mergeInsertSort(middle, last);
		mergeInsertSort(first, middle);
		std::inplace_merge(first, middle + 1, last + 1);
	}
	return ;
}

void binaryInsert(std::vector<int> &lst, int n) {
	std::vector<int>::iterator lower = std::lower_bound(lst.begin(), lst.end(), n);
	lst.insert(lower, n);
}

// template<class C>
void mIS(std::vector<int> &lst)
{
	int solo = -1;
	if (lst.size() % 2 != 0)
	{
		solo = lst.back();
		lst.pop_back();
	}
	if (lst.size() == 2)
	{
		if (lst[0] > lst[1])
			std::swap(lst[0], lst[1]);
		if (solo >= 0)
			binaryInsert(lst, solo);
		return ;
	}
	
	std::vector<std::pair<int, int> > pairs;
	for (size_t i = 0; i < lst.size(); i += 2)
	{
		pairs.push_back(std::make_pair(lst[i], lst[i + 1]));
		std::cout << "pair : lst[" << i << "] = " << lst[i] << " & lst[" << i + 1 << "] = " << lst[i + 1] << std::endl;
	}
	
	lst.clear();
	for (std::vector<std::pair<int, int> >::iterator i = pairs.begin(); i != pairs.end(); i++)
	{
		std::cout << "pair : [0] = " << i->first << " & [1] = " << i->second << std::endl;
		if (i->first > i->second)
			std::swap(i->first, i->second);
		lst.push_back(i->second);
		std::cout << lst.back() << std::endl;
	}
	std::cout << "lst =";
	for (size_t i = 0; i < lst.size(); i ++)
		std::cout << " " << lst[i] << std::endl;
	
	mIS(lst);
	
	if (solo >= 0)
		binaryInsert(lst, solo);
	for (std::vector<std::pair<int, int> >::iterator i = pairs.begin(); i != pairs.end(); i++)
		binaryInsert(lst, i->first);
}

void PmergeMe::sortSequence() {
	const std::clock_t cv_Start = std::clock();
	// mergeInsertSort(_vct.begin(), _vct.end() - 1);
	mIS(_vct);
	const std::clock_t cv_End = std::clock();
	std::cout << "After (vector) = ";
	for (std::vector<int>::iterator i = _vct.begin(); i != _vct.end(); i++)
		std::cout << " " << *i;
	std::cout << std::endl;
	std::cout << "Time to process a range of " << _vct.size() << " elements with std::vector : " << 1000.0 * (cv_End - cv_Start) / CLOCKS_PER_SEC << "ms" << std::endl;
	
	const std::clock_t cd_Start = std::clock();
	mergeInsertSort(_dq.begin(), _dq.end() - 1);
	const std::clock_t cd_End = std::clock();
	std::cout << "After (deque) = ";
	for (std::deque<int>::iterator i = _dq.begin(); i != _dq.end(); i++)
		std::cout << " " << *i;
	std::cout << std::endl;
	std::cout << "Time to process a range of " << _dq.size() << " elements with std::deque : " << 1000.0 * (cd_End - cd_Start) / CLOCKS_PER_SEC << "ms" << std::endl;
}


/*
	EXCEPTIONS DEFINITION
*/

const char* PmergeMe::InputErrorException::what() const throw() {
	return "\e[1;31mError: input not accepted.\e[0m";
}

/*
	OTHER FUNCTIONS
*/

double timediff(struct timeval Start, struct timeval End) {
	return (End.tv_sec * 1000 + End.tv_usec / 1000) - (Start.tv_sec * 1000 + Start.tv_usec / 1000);
}