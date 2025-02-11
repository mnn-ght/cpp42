/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:34:28 by magahat           #+#    #+#             */
/*   Updated: 2025/02/11 15:44:51 by magahat          ###   ########.fr       */
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


class PmergeMe
{
private:
	size_t _nbElements;
	
	std::vector<int> _vct;
	std::deque<int> _dq;
	
	std::vector<int> _jacobsthalSequence;
	bool parseNumbers(char **input);
	
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

#endif