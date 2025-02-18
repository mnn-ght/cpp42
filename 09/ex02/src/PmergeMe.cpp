/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   PmergeMe.cpp									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: magahat <magahat@student.42.fr>			+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/11/27 15:54:30 by magahat		   #+#	#+#			 */
/*   Updated: 2025/02/08 14:52:40 by magahat		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"


/*
	CONSTRUCTORS
*/

PmergeMe::PmergeMe(int nbElements, char **input) : _nbElements(nbElements), _vct(), _dq() {
	if (!parseNumbers(input, nbElements))
		throw InputErrorException();
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
	if (this != &other) {
		_vct = other._vct;
		_dq = other._dq;
	}
	return (*this);
}

/*
	MEMBER FUNCTIONS
*/

bool PmergeMe::parseNumbers(char **input, int nbElements) {
	char *str_end;
	if (nbElements < 2)
		return false;
	for (size_t i = 1; input[i]; i++)
	{
		long nb = std::strtol(input[i], &str_end, 10);
		const bool range_error = errno == ERANGE;
		if (nb < 0 || nb > INT_MAX || str_end[0] != 0 || range_error)
			return false;
		_vct.push_back(static_cast<int>(nb));
		_dq.push_back(static_cast<int>(nb));
	}
	if (_vct.size() != _nbElements || _dq.size() != _nbElements)
		return false;
	for (std::vector<int>::iterator it = _vct.begin(); it + 1 != _vct.end(); it++)
	{
		std::vector<int>::iterator jt = it + 1;
		for (; jt != _vct.end(); jt++)
		{
			if (*it == *jt)
				return false;
		}
	}
	return true;
}

void PmergeMe::sortSequence() {
	std::cout << "\e[1;35m====================== Listes before ======================\e[0m" << std::endl;
	printCont(_vct, "Before", 0);
	printCont(_dq, "Before", 0);
	
	std::cout << std::endl;
	std::cout << "\e[1;35m====================== Vector through Algo Ford Johnson ======================\e[0m" << std::endl;
	const std::clock_t cv_Start = std::clock();
	sortPairs(_vct, 0);
	const std::clock_t cv_End = std::clock();
	printCont(_vct, "After", 0);
	isSorted(_vct);
	std::cout << "Time to process a range of " << _vct.size() << " elements with std::vector : " << 1000.0 * (cv_End - cv_Start) / CLOCKS_PER_SEC << "ms" << std::endl;
	
	std::cout << std::endl;
	std::cout << "\e[1;35m====================== Deque through Algo Ford Johnson ======================\e[0m" << std::endl;
	const std::clock_t cd_Start = std::clock();
	sortPairs(_dq, 0);
	const std::clock_t cd_End = std::clock();
	printCont(_dq, "After", 0);
	isSorted(_dq);
	std::cout << "Time to process a range of " << _dq.size() << " elements with std::deque : " << 1000.0 * (cd_End - cd_Start) / CLOCKS_PER_SEC << "ms" << std::endl;
	std::cout << std::endl;
}


/*
	EXCEPTIONS DEFINITION
*/

const char* PmergeMe::InputErrorException::what() const throw() {
	return "\e[1;31mError: input not accepted.\e[0m";
}

/* OTHER FUNCTIONS */

double timediff(struct timeval Start, struct timeval End) {
	return (End.tv_sec * 1000 + End.tv_usec / 1000) - (Start.tv_sec * 1000 + Start.tv_usec / 1000);
}
