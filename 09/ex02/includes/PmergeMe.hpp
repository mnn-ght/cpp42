/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:34:28 by magahat           #+#    #+#             */
/*   Updated: 2025/01/26 12:20:17 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <set>

class PmergeMe
{
private:
	
	
public:
	PmergeMe();
	PmergeMe(std::string filename);
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);
	
	~PmergeMe() {};
};


#endif