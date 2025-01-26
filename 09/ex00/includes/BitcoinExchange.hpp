/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:34:28 by magahat           #+#    #+#             */
/*   Updated: 2025/01/26 12:09:54 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>

class BitcoinExchange
{
private:
	std::map<std::string, int> _data;
	std::map<std::string, int> _input;
	
public:
	BitcoinExchange();
	BitcoinExchange(std::string filename);
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &other);
	
	~BitcoinExchange() {};
};


#endif