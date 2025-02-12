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
	if (nbElements < 1)
		throw InputErrorException();
	if (!parseNumbers(input))
		throw InputErrorException();
	std::cout << "Before:";
	for (std::vector<int>::iterator i = _vct.begin(); i != _vct.end(); i++)
		std::cout << " " << *i;
	std::cout << std::endl;
	std::cout << "Jacobsthal sequence:";
	_jacobsthalSequence.push_back(0);
	_jacobsthalSequence.push_back(1);
	for (int i = 2; _jacobsthalSequence[i - 1] + 2 * _jacobsthalSequence[i - 2] < nbElements; i++)
		_jacobsthalSequence.push_back(_jacobsthalSequence[i - 1] + 2 * _jacobsthalSequence[i - 2]);
	_jacobsthalSequence.push_back(nbElements);
	for (std::vector<int>::iterator i = _jacobsthalSequence.begin(); i != _jacobsthalSequence.end(); i++)
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

/* template<class Cit>
void binarySearchMerge(Cit first, Cit last, int step)
{
	// Cit middle = first + ((last - first) / 2);
	while (*last > *first)
		first += step;
	// std::cout << "first = " << *first << " //// last = " << *last << std::endl;
	// std::cout << "first - step + 1 = " << *(first - step + 1) << " //// last = " << *last << std::endl;
	
	if (*last < *first && last != first)
		std::swap_ranges(first - step + 1, ++first, first);
	return ;
} */

template <class T> 
typename T::iterator	getIt(T& cont, int pos) {
	typename T::iterator	it = cont.begin();

	if (pos < 0)
		return (cont.begin());
	if (pos >= static_cast<int>(cont.size()))
		return (cont.end());
	std::advance(it, pos);
	return (it);
}

std::vector<int> addHighRanges(std::vector<int> cont, int step) {
	int i = step;
	int j = 0;
	std::vector<int>::iterator a;
	std::vector<int>::iterator b;
	std::vector<int> tmp;
	tmp.resize(cont.size() / step / 2 * step);

	while (i < static_cast<int>(cont.size()))
	{ 
		a = getIt(cont, i);
		b = getIt(cont, i + step);
		if (a != cont.end())
			std::copy(a, b, tmp.begin() + j);
		i += step * 2;
		j += step;
	}
	std::cout << "Highest = ";
	for (std::vector<int>::iterator i = tmp.begin(); i != tmp.end(); i++)
		std::cout << *i << " - ";
	std::cout << std::endl;
	return tmp;
}

std::vector<int> addLowRanges(std::vector<int> cont, int step) {
	int i = 0;
	int j = 0;
	std::vector<int>::iterator a;
	std::vector<int>::iterator b;
	std::vector<int> tmp;
	tmp.resize(cont.size() - (cont.size() / step / 2 * step));

	while (i < static_cast<int>(cont.size()))
	{ 
		a = getIt(cont, i);
		b = getIt(cont, i + step);
		if (a != cont.end())
			std::copy(a, b, tmp.begin() + j);
		i += step * 2;
		j += step;
	}
	std::cout << "Lowest = ";
	for (std::vector<int>::iterator i = tmp.begin(); i != tmp.end(); i++)
		std::cout << *i << " - ";
	std::cout << std::endl;
	return tmp;
}

std::vector<int> insertSequence(int size) {
	std::cout << "Size insert = " << size << std::endl;
	std::vector<int> sequence;
	std::vector<int> jacobsthal;
	jacobsthal.push_back(0);
	jacobsthal.push_back(1);
	for (int i = 2; jacobsthal[i - 1] + 2 * jacobsthal[i - 2] < size; i++)
		jacobsthal.push_back(jacobsthal[i - 1] + 2 * jacobsthal[i - 2]);
	jacobsthal.push_back(size);
	std::cout << "Jacobsthal sequence:";
	for (std::vector<int>::iterator i = jacobsthal.begin(); i != jacobsthal.end(); i++)
		std::cout << " " << *i;
	std::cout << std::endl;

	for (unsigned int i = 1; i < jacobsthal.size(); i++)
	{
		int current = jacobsthal[i];
		while (current > jacobsthal[i - 1])
		{
			sequence.push_back(current);
			current --;
		}
	}
	std::cout << "Sequence = ";
	for (std::vector<int>::iterator i = sequence.begin(); i != sequence.end(); i++)
		std::cout << *i << " - ";
	std::cout << std::endl;
	return sequence;
}

/* int getnb(std::vector<int>::iterator it, std::vector<int> cont)
{
	int n = 0;
	for (std::vector<int>::iterator i = cont.begin(); i != it; i++) {n++;}
	return n;
} */

std::vector<int>::iterator binarySearch(std::vector<int>::iterator first, std::vector<int>::iterator last, int step, int value, std::vector<int> cont) {
	(void) cont;
	std::cout << "===========\nLes comparaisons " << step << " : ";
	for (std::vector<int>::iterator i = first; i <= last; i++)
		std::cout << *i << " - ";
	std::cout << "\n===========" << std::endl;
	while (1)
	{
		// std::cout << "last - first = " << (last - first) / 2 << " /// std::distance = " << std::distance(first, last) << std::endl;
		int lmf = std::distance(first, last) / step * step - 1;
		std::vector<int>::iterator middle = first + lmf;
		std::cout << "middle = " << *middle << std::endl;
		if (std::distance(first, last) > step) {
			std::cout << "value = " << value << " compared to " << *middle << std::endl;
			if (value < *middle)
			{
				last = middle;
			}
			else
				first = middle;
		}
		if (std::distance(first, last) <= step) {
			if (value < *middle)
				return first;
			else 
			{
				std::cout << "value = " << value << " compared to " << *last << std::endl;
				if (value > *last)
					return last + 1;
				else
					return last - step + 1;
			}
		}
		middle = first + ((last - first) / 2);
	}
	return first;
}

/* void iteratorsOfPairs(std::vector<std::vector<int>::iterator> *toReturn, std::vector<int> cont, std::vector<int> insertionSequence, int step) {
	for (unsigned int i = 0; i < insertionSequence.size(); i++) {
		toReturn->push_back(getIt(cont, insertionSequence[i] * step - 1));
	}
	std::cout << "===========\nIterators : ";
	for (std::vector<std::vector<int>::iterator>::iterator i = toReturn->begin(); i != toReturn->end(); i++)
		std::cout << " " << **i << std::endl;
} */

/* std::vector<std::vector<int>::iterator> *iteratorsOfPairs(std::vector<int> cont, std::vector<int> insertionSequence, int step) {
	std::vector<std::vector<int>::iterator> *toReturn = new std::vector<std::vector<int>::iterator>;
	for (unsigned int i = 0; i < insertionSequence.size(); i++) {
		toReturn->push_back(getIt(cont, insertionSequence[i] * step - 1));
	}
	std::cout << "===========\nIterators : ";
	for (std::vector<std::vector<int>::iterator>::iterator i = toReturn->begin(); i != toReturn->end(); i++)
		std::cout << " " << **i << std::endl;
	return toReturn;
} */

// template <class T>
void	mergeInsert(std::vector<int>& cont, int step) {
	std::vector<int>::iterator a;
	std::vector<int>::iterator b;
	std::vector<int>::iterator c;
	std::vector<int> highestPair;
	std::vector<int> lowestPair;
	std::vector<int> insertionSequence;
	int size = cont.size();
	highestPair = addHighRanges(cont, step);
	lowestPair = addLowRanges(cont, step);
	insertionSequence = insertSequence(cont.size() / (step * 2));

	cont.clear();
	// cont.resize(step);
	int j = 0;
	int k = 0;
	// for (int i = 0; i < size / (step * 2); i++)
	// {
	// 	cont.insert(cont.end(), getIt(highestPair, j), getIt(highestPair, j + step));
	// 	/* for (std::vector<int>::iterator i = cont.begin(); i != cont.end(); i++)
	// 		std::cout << *i << " / ";
	// 	std::cout << std::endl; */
	// 	if (i == 0)
	// 		cont.insert(cont.begin(), lowestPair.begin(), lowestPair.begin() + step);
	// 	else {
	// 		a = getIt(lowestPair, insertionSequence[i] * step - step);
	// 		// std::cout << *a << " - ";
	// 		b = getIt(lowestPair, insertionSequence[i] * step - 1);
	// 		// std::cout << *b << " - ";
	// 		c = binarySearch(cont.begin(), cont.end() - 1, step, *b, cont);
	// 		if (c == cont.begin())
	// 			cont.insert(c, a, b + 1);
	// 		else
	// 			cont.insert(c, a, b + 1);
	// 	}
	// 	j += step;
	// 	k += step * 2;
	// 	/* for (std::vector<int>::iterator i = cont.begin(); i != cont.end(); i++)
	// 		std::cout << *i << " - ";
	// 	std::cout << std::endl; */
	// }
	// std::cout << std::endl;

	// if (size % (step * 2) != 0)
	// {
	// 	a = getIt(lowestPair, lowestPair.size() - step);
	// 	c = binarySearch(cont.begin(), cont.end() - 1, step, *(lowestPair.end() - 1), cont);
	// 	if (c == cont.begin())
	// 		cont.insert(c, a, lowestPair.end());
	// 	else
	// 		cont.insert(c, a, lowestPair.end());
	// }

	// /* std::cout << "===========\nStep " << step << " : ";
	// for (std::vector<int>::iterator i = cont.begin(); i != cont.end(); i++)
	// 	std::cout << *i << " - ";
	// std::cout << "\n===========" << std::endl; */


	cont = highestPair;
	std::vector<int> itToPair = insertionSequence;
	std::vector<int> highestnb;
	for (std::vector<int>::iterator i = itToPair.begin(); i != itToPair.end(); i++)
	{
		*i = *i * step - 1;
		a = getIt(cont, *i);
		highestnb.push_back(*a);
	}

	std::cout << "\e[1;31m=========== Step " << step << " ===========\e[0m\n";
	std::cout << "Iterators = ";
	for (std::vector<int>::iterator i = highestnb.begin(); i != highestnb.end(); i++)
	{
		std::cout << " " << *i;
	}
	std::cout << std::endl;
	for (int i = 0; i < size / (step * 2); i++)
	{
		std::cout << "i = " << i << " /// size = " << size << " /// calcul = " << size / (step * 2) << std::endl;
		std::cout << "Vector = ";
		for (std::vector<int>::iterator i = cont.begin(); i != cont.end(); i++)
			std::cout << *i << " / ";
		std::cout << std::endl;
		std::cout << "Iterators = ";
		for (std::vector<int>::iterator it = itToPair.begin(); it != itToPair.end(); it++)
		{
			a = getIt(cont, *it);
			std::cout << " " << *a;
		}
		std::cout << std::endl;
		if (i == 0)
		{
			cont.insert(cont.begin(), lowestPair.begin(), lowestPair.begin() + step);
			for (std::vector<int>::iterator it = itToPair.begin(); it != itToPair.end(); it++)
				*it = *it + step;
		}
		else {
			std::cout << "Range = ";
			a = getIt(lowestPair, insertionSequence[i] * step - step);
			std::cout << *a << " - ";
			b = getIt(lowestPair, insertionSequence[i] * step - 1);
			std::cout << *b << std::endl;
			c = binarySearch(cont.begin(), getIt(cont, itToPair[i]) - step, step, *b, cont);
			cont.insert(c, a, b + 1);
			for (int j = i; j < static_cast<int>(itToPair.size()); j++)
			{
				if (highestnb[j] != *getIt(cont, itToPair[j]))
					itToPair[j] = itToPair[j] + step;
			}
		}
		j += step;
		k += step * 2;
		for (std::vector<int>::iterator i = cont.begin(); i != cont.end(); i++)
			std::cout << *i << " - ";
		std::cout << std::endl;
	}

	if (size % (step * 2) != 0)
	{
		a = getIt(lowestPair, lowestPair.size() - step);
		c = binarySearch(cont.begin(), cont.end() - 1, step, *(lowestPair.end() - 1), cont);
		if (c == cont.begin())
			cont.insert(c, a, lowestPair.end());
		else
			cont.insert(c, a, lowestPair.end());
	}

	std::cout << "===========\nTest " << step << " : ";
	for (std::vector<int>::iterator i = cont.begin(); i != cont.end(); i++)
		std::cout << *i << " - ";
	std::cout << "\n===========" << std::endl;
}

// Algorithhm de tri par pair
/* template <class T> */
void	sortPairs(std::vector<int>& cont, int level) {
	int step = std::pow(2, level);
	int i = step - 1;
	std::vector<int>::iterator a;
	std::vector<int>::iterator b;

	std::cout << "level = " << level << " \\\\ step = " << step << " \\\\ container size = " << static_cast<int>(cont.size()) << std::endl;
	while (i < static_cast<int>(cont.size())) {
		a = getIt(cont, i);
		b = getIt(cont, i + step);
		if (a != cont.end() && b != cont.end() && *a > *b)
			std::swap_ranges(getIt(cont, i - step + 1), ++a, a);
		i += 2 * step;
	}
	for (std::vector<int>::iterator i = cont.begin(); i != cont.end(); i++)
		std::cout << *i << " - ";
	std::cout << std::endl;
	if (cont.size() / step > 1)
		sortPairs(cont, ++level);
	if (step > 1)
		mergeInsert(cont, step / 2);
}


void PmergeMe::sortSequence() {
	const std::clock_t cv_Start = std::clock();
	sortPairs(_vct, 0);
	const std::clock_t cv_End = std::clock();
	std::cout << "After (vector) = ";
	for (std::vector<int>::iterator i = _vct.begin(); i != _vct.end(); i++)
		std::cout << " " << *i;
	std::cout << std::endl;
	std::cout << "Time to process a range of " << _vct.size() << " elements with std::vector : " << 1000.0 * (cv_End - cv_Start) / CLOCKS_PER_SEC << "ms" << std::endl;
	
	/* const std::clock_t cd_Start = std::clock();
	sortPairs(_dq, 0);
	const std::clock_t cd_End = std::clock();
	std::cout << "After (deque) = ";
	for (std::deque<int>::iterator i = _dq.begin(); i != _dq.end(); i++)
		std::cout << " " << *i;
	std::cout << std::endl;
	std::cout << "Time to process a range of " << _dq.size() << " elements with std::deque : " << 1000.0 * (cd_End - cd_Start) / CLOCKS_PER_SEC << "ms" << std::endl; */
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