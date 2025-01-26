/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magahat <magahat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:54:30 by magahat           #+#    #+#             */
/*   Updated: 2025/01/26 17:16:29 by magahat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"

/*
	CONSTRUCTORS
*/

BitcoinExchange::BitcoinExchange(void) {
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
	*this = other;
}

/*
	DESTRUCTORS
*/

BitcoinExchange::~BitcoinExchange() {
}

/*
	OPERATORS OVERLOAD
*/

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
		_data = other._data;
	return (*this);
}

/*
	MEMBER FUNCTIONS
*/

void BitcoinExchange::setDataMapFromRaw() {
	std::ifstream inData("data.csv", std::ifstream::in);
	if (inData.is_open() == false)
		throw DataFileErrorOpenning();
	std::string token;
	std::getline(inData, token, '\n');
	if (token.compare("date,exchange_rate"))
		throw DataFileErrorInside();
	while (std::getline(inData, token, '\n'))
	{
		size_t pos = token.find(',');
		if (pos == std::string::npos || pos + 1 == token.size())
			throw DataFileErrorInside();
		try
		{
			setDataMap(token.substr(0, pos), token.substr(pos + 1, token.length()));
		}
		catch(const std::exception& e)
		{
			throw DataFileErrorInside();
		}
	}
	inData.close();
}

void BitcoinExchange::setDataMap(std::string key, std::string value) {
	if (checkDate(key) == false)
		throw DataFileErrorInside();
	if (checkValue(value, 0) != 0)
		throw DataFileErrorInside();
	_data[key] = std::atof(value.c_str());
}

void BitcoinExchange::manageInput(std::string filename) {
	std::ifstream inInput(filename.c_str(), std::ifstream::in);
	if (inInput.is_open() == false)
		throw InputFileErrorOpenning();
	std::string token;
	std::string date;
	std::string value;
	std::getline(inInput, token, '\n');
	if (token.compare("date | value"))
		throw InputFileErrorInside();
	while (std::getline(inInput, token, '\n'))
	{
		size_t pos = token.find(" | ");
		date = token.substr(0, pos);
		value = token.substr(pos + 3, token.length());
		if (checkDate(date) == false)
			std::cout << "Error: bad input => " << date << std::endl;
		else if (value.empty())
			std::cout << "Error: no input => " << date << std::endl;
		else
		{
			switch (checkValue(value, 1))
			{
			case 1:
				std::cout << "Error: bad input => " << value << " (" << date << ")" << std::endl;
				break;
			case 2:
				std::cout << "Error: not a positive number." << std::endl;
				break;
			case 3:
				std::cout << "Error: too large a number." << std::endl;
				break;
			case 0:
				double btcValue = getValue(date, std::atof(value.c_str()));
				if (btcValue < 0)
					std::cout << "Error: date too anterior (min " << _data.begin()->first << ") => " << date << std::endl;
				else
					std::cout << date << " => " << value << " = " << btcValue << std::endl;
				break;
			}
		}
	}
	inInput.close();
}

double BitcoinExchange::getValue(std::string date, double value) {
	std::map<std::string, double>::const_iterator it = _data.find(date);
	if (it != _data.end())
		return it->second * value;
	for (std::map<std::string, double>::iterator i = _data.begin(); i != _data.end(); i++)
	{
		if (date.compare(i->first) < 0 && i != _data.begin())
		{
			it = --i;
			break;
		}
		else if (date.compare(i->first) < 0 && i == _data.begin())
			return -1;
	}
	return it->second * value;
}

/*
	EXCEPTIONS DEFINITION
*/

const char* BitcoinExchange::DataFileErrorOpenning::what() const throw() {
	return "\e[1;31mError: could not open file 'data.csv'. Check if the file exist or have the enough authorizations.\e[0m";
}
const char* BitcoinExchange::DataFileErrorInside::what() const throw() {
	return "\e[1;31mError: data file is corrupted. Update the file 'data.csv' with a valid one.\e[0m";
}
const char* BitcoinExchange::InputFileErrorOpenning::what() const throw() {
	return "\e[1;31mError: could not open the input file. Check if the file exist or have the enough authorizations.\e[0m";
}
const char* BitcoinExchange::InputFileErrorInside::what() const throw() {
	return "\e[1;31mError: input file has not a valid format.\e[0m";
}

/*
	OTHER FUNCTIONS
*/

bool checkDate(std::string date) {
	std::istringstream ss(date);
	std::string token;
	int	days;
	bool	leap = 0;
	std::getline(ss, token, '-');
	if(token.size() != 4)
		return false;
	if (std::atoi(token.c_str()) % 4 == 0)
		leap = 1;
	std::getline(ss, token, '-');
	if(token.size() != 2 || std::atoi(token.c_str()) < 1 || std::atoi(token.c_str()) > 12)
		return false;
	else
	{
		if (token == "04" || token == "06" || token == "09" || token == "11")
			days = 30;
		else if (token == "02")
		{
			if (leap == 0)
				days = 28;
			else
				days = 29;
		}
		else
			days = 31;
	}
	std::getline(ss, token);
	if(token.size() != 2 || std::atoi(token.c_str()) < 1 || std::atoi(token.c_str()) > days)
		return false;
	return true;
}

int checkValue(std::string value, int flag) {
	double tmp = std::atof(value.c_str());
	if (tmp < 0)
		return 2;
	if (flag == 1 && tmp > 1000)
		return 3;
	
	bool point = 0;
	for (size_t i = 0; i < value.size(); i++)
	{
		if (value[i] == '.' && point == 0 && i > 0 && i != value.size() - 1)
			point = 1;
		else if (isdigit(value[i]) == 0)
			return 1;
		if (flag == 1 && value[i] == '.' && i > 3)
			return 3;
	}
	return 0;
}
