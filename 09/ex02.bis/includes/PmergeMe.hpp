/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:34:28 by magahat           #+#    #+#             */
/*   Updated: 2025/02/17 14:07:23 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <iterator>
#include <set>
#include <algorithm>
#include <cmath>
#include <vector>
#include <deque>
#include <utility>
#include <climits>
#include <ctime>
#include <cstdlib>
#include <sys/time.h>
#include <cerrno>

#define DEBUG 0

class PmergeMe
{
private:
	size_t _nbElements;
	
	std::vector<int> _vct;
	std::deque<int> _dq;
	
	std::vector<int> _jacobsthalSequence;
	bool parseNumbers(char **input, int nbElements);
	
public:
	PmergeMe();
	PmergeMe(int nbElements, char **input);
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);
	
	void sortSequence();

	class InputErrorException : public std::exception {
		const char* what() const throw();
	};
	
	~PmergeMe();
};

double timediff(struct timeval Start, struct timeval End);

template<class C>
typename C::iterator	getIt(C& cont, int pos);
template<class C>
void isSorted(C cont);
template<class C>
void printCont(C cont, std::string msg, bool debug);
template<class C, class Cit>
void printItvalue(C cont, Cit itCont, std::string msg);
template<class C>
C addHighRanges(C cont, int step);
template<class C>
C addLowRanges(C cont, int step);
template<class C>
C addSolo(C cont, int step);
template<class C>
C insertSequence(int size);
template<class Cit>
Cit binarySearch(Cit first, Cit last, int step, int value);
template<class C>
void	mergeInsert(C &cont, int step);
template<class C>
void	sortPairs(C &cont, int level);


#include "PmergeMe.tpp"
#endif