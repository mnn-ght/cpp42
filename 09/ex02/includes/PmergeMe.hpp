/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:34:28 by magahat           #+#    #+#             */
/*   Updated: 2025/01/27 12:13:01 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <set>
#include <vector>
#include <deque>
#include <utility>
#include <climits>
#include <cstdlib>


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
	void mergeInsertSort();

	class InputErrorException : public std::exception {
		const char* what() const throw();
	};
	
	~PmergeMe();
};


#endif