/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismherna <ismherna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 23:36:55 by ismherna          #+#    #+#             */
/*   Updated: 2025/03/20 23:36:57 by ismherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

/*=================================INCLUDES==================================*/

#include <iostream>
#include <vector>
#include <deque>
#include <stdlib.h>
#include <ctime>
#include <iterator>
#include <algorithm>

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
class PmergeMe
{
	private:
		std::vector<int>	_vector;
		std::deque<int>		_deque;

		void	add(int n);

		void	sortVector();
		void	sortDeque();

		template<typename T>
		static void insert(T& container);

		template <typename T>
		static void sort(T& m);

	public:
		PmergeMe(int ac, char **av);
		PmergeMe(PmergeMe const &src);
		PmergeMe &operator=(PmergeMe const &src);
		~PmergeMe();

		class DuplicateNumber : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class NegativeNumber : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif