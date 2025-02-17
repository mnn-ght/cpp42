/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:18:08 by magahat           #+#    #+#             */
/*   Updated: 2025/02/17 14:07:58 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

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
			std::cout << "\e[1;31m 🚨 ERROR : list not sorted 🚨 \e[0m" << std::endl;
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

template<class C>
C addHighRanges(C cont, int step) {
	int i = step;
	int j = 0;
	typename C::iterator a;
	typename C::iterator b;
	C tmp;
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
		for (typename C::iterator it = cont.begin(); it != cont.end(); it++, j++)
		{
			if (j % 2 == 1)
				tmp.push_back(*it);
		}
	}
	printCont(tmp, "Highest", 1);
	return tmp;
}

template<class C>
C addLowRanges(C cont, int step) {
	int i = 0;
	int j = 0;
	typename C::iterator a;
	typename C::iterator b;
	C tmp;
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
		for (typename C::iterator it = cont.begin(); it != cont.end(); it++, j++)
		{
			if (j % 2 == 0)
				tmp.push_back(*it);
		}
	}
		
	printCont(tmp, "Lowest", 1);
	return tmp;
}

template<class C>
C addSolo(C cont, int step) {
	C tmp;
	tmp.resize(cont.size() % step);
	
	std::copy(getIt(cont, cont.size() - cont.size() % step), cont.end(), tmp.begin());
	printCont(tmp, "Solo", 1);
	return tmp;
}



template<class C>
C insertSequence(int size) {
	// std::cout << "Size insert = " << size << std::endl;
	C sequence;
	C jacobsthal;
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

template<class Cit>
Cit binarySearch(Cit first, Cit last, int step, int value) {
	Cit middle;
	Cit base = first;
	int comp = 2;
	bool odd = (std::distance(first, last) / step) % 2;
	// std::cout << odd << std::endl;
	if (DEBUG == 1)
		{
			std::cout << "\e[3;31m{DEBUG} ";
			std::cout << "Range de la comparaison :";
			for (Cit i = first; i <= last; i++)
				std::cout << " " << *i;
			std::cout << "\e[0m" << std::endl;
		}
  
	while (std::distance(first, last) > step) {
		if (DEBUG == 1)
		{
			std::cout << "\e[3;31m{DEBUG} ";
			std::cout << "Range de la comparaison :";
			for (Cit i = first; i <= last; i++)
				std::cout << " " << *i;
			std::cout << "\e[0m" << std::endl;
		}
		middle = first;
		std::advance(middle, (std::distance(first, last) / 2));
		odd = (std::distance(first, last) / step) % 2;
		
		Cit tmp = middle;
		while (step > 1 && std::distance(base, tmp) % step != step - 1) {
			if (middle != last)
				tmp ++;
			else
				tmp --;
		}
		middle = tmp;

		if (DEBUG == 1)
			std::cout << "\e[3;31m{DEBUG} " << "value = " << value << " compared to middle = " << *middle << "\e[0m" << " odd ? = " << odd << std::endl;

		if (value < *middle)
		{
			// std::cout << std::distance(first, middle) << std::endl;
			if (std::distance(first, middle) < step)
			{
				if (comp == 0 && odd == 1)
					return (last - (step - 1));
				if (DEBUG == 1)
					std::cout << "\e[3;31m{DEBUG} " << "value = " << value << " compared to first = " << *first << "\e[0m" << " compcoucou = " << comp << std::endl;
				if (value < *(first + step - 1))
					return (first);
				else
					return (middle);
			}
			last = middle;
			if (step == 1)
				last--;
			comp = 1;
		}
		else
		{
			if (std::distance(middle, last) < step)
			{
				if (comp == 1 && odd == 1)
					return (last - (step - 1));
				if (DEBUG == 1)
					std::cout << "\e[3;31m{DEBUG} " << "value = " << value << " compared to last = " << *last << "\e[0m" << " comp = " << comp << std::endl;
				if (value > *last)
					return (++last);
				else
					return (++middle);
			}
			first = middle;
			if (step == 1)
				first++;
			comp = 0;
		}
	}
	
	if (DEBUG == 1)
		std::cout << "\e[3;31m{DEBUG} " << "value = " << value << " compared to first = " << *first << "\e[0m" << " comp = " << comp << std::endl;
	if (value < *first)
		return (first);
	if (DEBUG == 1)
		std::cout << "\e[3;31m{DEBUG} " << "value = " << value << " compared to last = " << *last << "\e[0m" << " comp = " << comp << std::endl;
	if (value > *last)
		return (++last);
	return (last - (step - 1));
}

template<class C>
void	mergeInsert(C &cont, int step) {
	typename C::iterator a;
	typename C::iterator b;
	typename C::iterator c;
	C highestPair;
	C lowestPair;
	C solo;
	C insertionSequence;
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
	insertionSequence = insertSequence<C >(cont.size() / (step * 2));

	cont.clear();
	cont = highestPair;
	C itToPair = insertionSequence;
	C highestnb;
	for (typename C::iterator i = itToPair.begin(); i != itToPair.end(); i++)
	{
		*i = *i * step - 1;
		a = getIt(cont, *i);
		highestnb.push_back(*a);
	}
	printCont(highestnb, "Highest nb that the lower will compare to", 1);

	for (int i = 0; i < size / (step * 2); i++)
	{
		if (DEBUG == 1)
			std::cout << "\n\e[3;34m{DEBUG} Etape " << i << " :" << std::endl;
		printCont(cont, "Container while in merge insert", 1);
		printItvalue(cont, itToPair, "Iterators");
		if (i == 0)
		{
			cont.insert(cont.begin(), lowestPair.begin(), lowestPair.begin() + step);
			for (typename C::iterator it = itToPair.begin(); it != itToPair.end(); it++)
				*it = *it + step;
		}
		else {
			a = getIt(lowestPair, insertionSequence[i] * step - step);
			b = getIt(lowestPair, insertionSequence[i] * step - 1);
			if (DEBUG == 1)
				std::cout << "\e[3;31m{DEBUG} Range a comparer = " << *a << " to " << *b << " (= valeur a comparer aux highest nb)\e[0m" << std::endl;
			c = binarySearch(cont.begin(), getIt(cont, itToPair[i]) - step, step, *b);
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
		c = binarySearch(cont.begin(), cont.end() - 1, step, *(lowestPair.end() - 1));
		cont.insert(c, a, lowestPair.end());
	}
	if (!solo.empty())
		cont.insert(cont.end(), solo.begin(), solo.end());
	
	printCont(cont, "Container at the end of the step in Merge Insert", 1);
}

template<class C>
void	sortPairs(C &cont, int level) {
	int step = std::pow(2, level);
	int i = step - 1;
	typename C::iterator a;
	typename C::iterator b;

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
