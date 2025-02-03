/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:34:28 by magahat           #+#    #+#             */
/*   Updated: 2025/01/28 12:14:59 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <set>
#include <algorithm>
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