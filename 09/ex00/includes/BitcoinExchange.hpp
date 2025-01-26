/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:34:28 by magahat           #+#    #+#             */
/*   Updated: 2025/01/26 16:33:56 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <cstdlib>
#include <map>
#include <sstream>
#include <fstream>

class BitcoinExchange
{
private:
	std::map<std::string, double> _data;
	
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &other);
	
	~BitcoinExchange();

	void setDataMapFromRaw();
	void setDataMap(std::string key, std::string value);
	void manageInput(std::string filename);
	double getValue(std::string date, double value);

	class DataFileErrorOpenning : public std::exception {
		const char *what() const throw();
	};
	class DataFileErrorInside : public std::exception {
		const char *what() const throw();
	};
	class InputFileErrorOpenning : public std::exception {
		const char *what() const throw();
	};
	class InputFileErrorInside : public std::exception {
		const char *what() const throw();
	};
	
};

bool checkDate(std::string date);
int checkValue(std::string value, int flag);

#endif