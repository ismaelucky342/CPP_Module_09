/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismherna <ismherna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 23:44:30 by ismherna          #+#    #+#             */
/*   Updated: 2025/03/20 23:44:31 by ismherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string input)
{
	std::ifstream file;
	std::ifstream database;
	std::string line;
	std::string lines;

	file.open(input.c_str());
	database.open("data.csv");

	if (database.is_open())
	{
		std::getline(database, line);
		while (std::getline(database, line))
		{
			try {
				char *end;
				std::string date = line.substr(0, line.find(","));
				double value = std::strtod(line.substr(line.find(",") + 1).c_str(), &end);
				this->_data.insert(std::pair<std::string, double>(date, value));
			} catch (const std::exception& e) {
				std::cerr << RED "ERROR: bad input => " RESET << line << std::endl;
				continue;
			}
		}
		database.close();

		if (file.is_open())
		{
			std::pair<std::string, std::string> pair;
			std::getline(file, line);
			while (std::getline(file, line))
			{
				pair = split(line, '|');

				if (pair.first.empty() || pair.second.empty())
				{
					std::cerr << RED "ERROR: bad input => " RESET << line << std::endl;
					continue;
				}

				char*	end;
				double	value = std::strtod(pair.second.c_str(), &end);
				double	rate = getExchangeRate(pair.first);

				if ((value * rate) > std::numeric_limits<int>::max())
				{
					std::cerr << RED "ERROR: too large a number." RESET << std::endl;
					continue;
				}
				if (value < 0)
				{
					std::cerr << RED "ERROR: not a positive number." RESET << std::endl;
					continue;
				}
				std::cout << removeSpaces(pair.first) << " => " << removeSpaces(pair.second) << " = " << value * rate << std::endl;
			}
			file.close();
		}
		else
		{
			std::cerr << RED "ERROR: could not open file." RESET << std::endl;
		}
	}
	else
		std::cerr << RED "ERROR: could not open database." RESET << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
	*this = src;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs)
{
	if (this != &rhs)
	{
		this->_data = rhs._data;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{}

void	BitcoinExchange::insert(std::string date, double value)
{
	this->_data.insert(std::pair<std::string, double>(date, value));
}

double	BitcoinExchange::getExchangeRate(std::string date)
{
	std::map<std::string, double>::iterator it = this->_data.lower_bound(date);

	if (it->first == date)
	{
		return it->second;
	}
	else if (it == this->_data.begin())
	{
		std::cerr << RED "ERROR: no data found for date " RESET << date << std::endl;
		return 0;
	}
	else
	{
		return (--it)->second;
	}
}

std::pair<std::string, std::string>	split(std::string str, char delimiter)
{
	std::pair<std::string, std::string> pair;
	size_t start = str.find(delimiter);

	if (start == std::string::npos)
		return pair;

	pair.first = str.substr(0, start);
	pair.second = str.substr(start + 1);
	if (pair.second.find(delimiter) != std::string::npos)
	{
		pair.first.clear();
		pair.second.clear();
	}
	return pair;
}

std::string	removeSpaces(std::string str)
{
	const std::string space = " \n\r\t";

	str.erase(str.find_last_not_of(space) + 1);
	str.erase(0, str.find_first_not_of(space));
	return str;
}
