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

template<class C>
void isSorted(C cont) {
	for (typename C::iterator i = cont.begin() + 1; i != cont.end(); i++)
	{
		if (*i < *(i - 1))
		{
			std::cout << "\e[3;31mERROR : list not sorted" << std::endl;
			return ;
		}
	}
}

template<class C>
void printCont(C cont, std::string msg, bool debug) {
	if (debug == 0)
		std::cout << "\e[1m" << msg << " =";
	else if (DEBUG == 1)
		std::cout << "\e[3;31m{DEBUG} " << msg << " =";
	else
		return;
	for (typename C::iterator i = cont.begin(); i != cont.end(); i++)
	{
		std::cout << " " << *i;
	}
	std::cout << "\e[0m" << std::endl;
}

template<class C, class Cit>
void printItvalue(C cont, Cit itCont, std::string msg) {
	if (DEBUG == 0)
		return;
	typename Cit::iterator a;
	std::cout << "\e[3;31m{DEBUG} " << msg << " =";
	for (typename C::iterator i = itCont.begin(); i != itCont.end(); i++)
	{
		a = getIt(cont, *i);
		std::cout << " " << *a;
	}
	std::cout << "\e[0m" << std::endl;
}

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

std::vector<int> addHighRanges(std::vector<int> cont, int step) {
	int i = step;
	int j = 0;
	std::vector<int>::iterator a;
	std::vector<int>::iterator b;
	std::vector<int> tmp;
	if (step > 1)
	{
		tmp.resize(cont.size() / step / 2 * step);
		while (i < static_cast<int>(cont.size()))
		{
			a = getIt(cont, i);
			b = getIt(cont, i + step);
			if (a != cont.end() && b != cont.end())
					std::copy(a, b, tmp.begin() + j);
			if (a != cont.end() && b == cont.end() && cont.size() % (step) == 0)
				std::copy(a, a + step, tmp.begin() + j);
			i += step * 2;
			j += step;
		}
	}
	else {
		for (std::vector<int>::iterator it = cont.begin(); it != cont.end(); it++, j++)
		{
			if (j % 2 == 1)
				tmp.push_back(*it);
		}
	}
	printCont(tmp, "Highest", 1);
	return tmp;
}

std::vector<int> addLowRanges(std::vector<int> cont, int step) {
	int i = 0;
	int j = 0;
	std::vector<int>::iterator a;
	std::vector<int>::iterator b;
	std::vector<int> tmp;
	if (step > 1)
	{
		tmp.resize(cont.size() - (cont.size() / step / 2 * step) - cont.size() % step);
		while (i < static_cast<int>(cont.size()))
		{
			a = getIt(cont, i);
			b = getIt(cont, i + step);
			if (a != cont.end() && b != cont.end())
				std::copy(a, b, tmp.begin() + j);
			if (a != cont.end() && b == cont.end() && cont.size() % (step) == 0)
				std::copy(a, a + step, tmp.begin() + j);
			i += step * 2;
			j += step;
		}
	}
	else
	{
		for (std::vector<int>::iterator it = cont.begin(); it != cont.end(); it++, j++)
		{
			if (j % 2 == 0)
				tmp.push_back(*it);
		}
	}
		
	printCont(tmp, "Lowest", 1);
	return tmp;
}

std::vector<int> addSolo(std::vector<int> cont, int step) {
	std::vector<int> tmp;
	tmp.resize(cont.size() % step);
	
	std::copy(getIt(cont, cont.size() - cont.size() % step), cont.end(), tmp.begin());
	printCont(tmp, "Solo", 1);
	return tmp;
}

std::vector<int> insertSequence(int size) {
	// std::cout << "Size insert = " << size << std::endl;
	std::vector<int> sequence;
	std::vector<int> jacobsthal;
	jacobsthal.push_back(0);
	jacobsthal.push_back(1);
	for (int i = 2; jacobsthal[i - 1] + 2 * jacobsthal[i - 2] < size; i++)
		jacobsthal.push_back(jacobsthal[i - 1] + 2 * jacobsthal[i - 2]);
	jacobsthal.push_back(size);
	printCont(jacobsthal, "Jacobsthal sequence", 1);

	for (unsigned int i = 1; i < jacobsthal.size(); i++)
	{
		int current = jacobsthal[i];
		while (current > jacobsthal[i - 1])
		{
			sequence.push_back(current);
			current --;
		}
	}
	printCont(sequence, "Insertion Sequence", 1);
	return sequence;
}


std::vector<int>::iterator binarySearch(std::vector<int>::iterator first, std::vector<int>::iterator last, int step, int value, std::vector<int> cont) {
	(void) cont;
	if (DEBUG == 1)
	{
		std::cout << "\e[3;31m{DEBUG} ";
		std::cout << "Range de la comparaison :";
		for (std::vector<int>::iterator i = first; i <= last; i++)
			std::cout << " " << *i;
		std::cout << "\e[0m" << std::endl;
	}
	std::vector<int>::iterator middle;
	std::vector<int>::iterator base = first;
  
	while (std::distance(first, last) > step) {
		middle = first;
		std::advance(middle, (std::distance(first, last) / 2));

		std::vector<int>::iterator tmp = middle;
		while (step > 1 && std::distance(base, tmp) % step != step - 1) {
			if (middle != last)
				tmp ++;
			else
				tmp --;
		}
		middle = tmp;

		if (DEBUG == 1)
			std::cout << "\e[3;31m{DEBUG} " << "value = " << value << " compared to middle = " << *middle << "\e[0m" << std::endl;

		if (value < *middle)
			last = middle;
		else
			first = middle;
	}
	if (value < *first)
		return (first);
	if (value > *last)
		return (++last);
	return (last - (step - 1));
}

void	mergeInsert(std::vector<int>& cont, int step) {
	std::vector<int>::iterator a;
	std::vector<int>::iterator b;
	std::vector<int>::iterator c;
	std::vector<int> highestPair;
	std::vector<int> lowestPair;
	std::vector<int> solo;
	std::vector<int> insertionSequence;
	int size = cont.size();
	if (DEBUG == 1)
	{
		std::cout << "\e[1;34m======================" << " Step " << step << " in Merge Insertion ======================" << std::endl;
		std::cout << "\tSize of container = " << size << "\e[0m" << std::endl;
	}
	highestPair = addHighRanges(cont, step);
	lowestPair = addLowRanges(cont, step);
	if (cont.size() % step != 0)
		solo = addSolo(cont, step);
	insertionSequence = insertSequence(cont.size() / (step * 2));

	cont.clear();
	cont = highestPair;
	std::vector<int> itToPair = insertionSequence;
	std::vector<int> highestnb;
	for (std::vector<int>::iterator i = itToPair.begin(); i != itToPair.end(); i++)
	{
		*i = *i * step - 1;
		a = getIt(cont, *i);
		highestnb.push_back(*a);
	}
	printCont(highestnb, "Highest nb that the lower will compare to", 1);

	for (int i = 0; i < size / (step * 2); i++)
	{
		printCont(cont, "Container while in merge insert", 1);
		printItvalue(cont, itToPair, "Iterators");
		if (i == 0)
		{
			cont.insert(cont.begin(), lowestPair.begin(), lowestPair.begin() + step);
			for (std::vector<int>::iterator it = itToPair.begin(); it != itToPair.end(); it++)
				*it = *it + step;
		}
		else {
			a = getIt(lowestPair, insertionSequence[i] * step - step);
			b = getIt(lowestPair, insertionSequence[i] * step - 1);
			if (DEBUG == 1)
				std::cout << "\e[3;31m{DEBUG} Range a comparer = " << *a << " to " << *b << "\e[0m" << std::endl;
			c = binarySearch(cont.begin(), getIt(cont, itToPair[i]) - step, step, *b, cont);
			cont.insert(c, a, b + 1);
			for (int j = 0; j < static_cast<int>(itToPair.size()); j++)
			{
				if (highestnb[j] != *getIt(cont, itToPair[j]))
					itToPair[j] = itToPair[j] + step;
			}
		}
	}

	if (lowestPair.size() != highestPair.size())
	{
		a = getIt(lowestPair, lowestPair.size() - step);
		c = binarySearch(cont.begin(), cont.end() - 1, step, *(lowestPair.end() - 1), cont);
		cont.insert(c, a, lowestPair.end());
	}
	if (!solo.empty())
		cont.insert(cont.end(), solo.begin(), solo.end());
	
	printCont(cont, "Container at the end of the step in Merge Insert", 1);
}

void	sortPairs(std::vector<int>& cont, int level) {
	int step = std::pow(2, level);
	int i = step - 1;
	std::vector<int>::iterator a;
	std::vector<int>::iterator b;

	if (DEBUG == 1)
	{
		std::cout << "\e[1;32m======================" << " Step " << step << " in Sort Pair ======================" << std::endl;
		std::cout << "\tLevel = " << level << std::endl;
		std::cout << "\tContainer size = " << static_cast<int>(cont.size()) << "\e[0m" << std::endl;
	}
	while (i < static_cast<int>(cont.size())) {
		a = getIt(cont, i);
		b = getIt(cont, i + step);
		if (a != cont.end() && b != cont.end() && *a > *b)
			std::swap_ranges(getIt(cont, i - step + 1), ++a, a);
		i += 2 * step;
	}
	printCont(cont, "Container at the end of the step in sort Pair", 1);
	if (cont.size() / step > 1)
		sortPairs(cont, ++level);
	if (step > 1)
		mergeInsert(cont, step / 2);
}


void PmergeMe::sortSequence() {
	std::cout << "\e[1;35m====================== Vector through Algo Ford Johnson ======================\e[0m" << std::endl;
	const std::clock_t cv_Start = std::clock();
	printCont(_vct, "Before", 0);
	sortPairs(_vct, 0);
	const std::clock_t cv_End = std::clock();
	printCont(_vct, "After", 0);
	isSorted(_vct);
	std::cout << "Time to process a range of " << _vct.size() << " elements with std::vector : " << 1000.0 * (cv_End - cv_Start) / CLOCKS_PER_SEC << "ms" << std::endl;
	
	std::cout << "\e[1;35m====================== Deque through Algo Ford Johnson ======================\e[0m" << std::endl;
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
	return "\e[3;31mError: input not accepted.\e[0m";
}

/*
	OTHER FUNCTIONS
*/

double timediff(struct timeval Start, struct timeval End) {
	return (End.tv_sec * 1000 + End.tv_usec / 1000) - (Start.tv_sec * 1000 + Start.tv_usec / 1000);
}

