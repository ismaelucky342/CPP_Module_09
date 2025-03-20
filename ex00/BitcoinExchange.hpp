/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismherna <ismherna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 23:44:35 by ismherna          #+#    #+#             */
/*   Updated: 2025/03/20 23:44:36 by ismherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

/*=================================INCLUDES==================================*/

#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <map>
#include <limits>

/*================================COLORS=====================================*/

# define RESET "\033[0m"
# define BLACK "\033[30m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"
# define WHITE "\033[37m"
# define GRAY "\033[90m"

# define B_BLACK "\033[40m"
# define B_RED "\033[41m"
# define B_GREEN "\033[42m"
# define B_YELLOW "\033[43m"
# define B_BLUE "\033[44m"
# define B_MAGENTA "\033[45m"
# define B_CYAN "\033[46m"
# define B_WHITE "\033[47m"
# define B_GRAY "\033[100m"

/*================================CLASS=====================================*/

class BitcoinExchange
{
private:
	std::map<std::string, double> _data;

public:
	BitcoinExchange(std::string str);
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &other);
	~BitcoinExchange();

	void	insert(std::string date, double value);
	double	getExchangeRate(std::string date);
};

/*================================FUNCTIONS=================================*/

std::string	removeSpaces(std::string str);
std::pair<std::string, std::string>	split(std::string str, char delimiter);

#endif