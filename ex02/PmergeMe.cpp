/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismherna <ismherna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 23:45:59 by ismherna          #+#    #+#             */
/*   Updated: 2025/03/20 23:46:00 by ismherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int ac, char **av)
{
	for (int i = 1; i < ac; i++)
			add(std::atoi(av[i]));

	std::cout << YELLOW << "Before: " << RESET;
	for (std::size_t i = 0; i < _vector.size(); i++)
		std::cout << _vector[i] << " ";
	std::cout << std::endl;

	clock_t	start_vector = clock();
	sortVector();
	clock_t	end_vector = clock();
	double	time_vector = double(end_vector - start_vector) / CLOCKS_PER_SEC;

	clock_t	start_deque = clock();
	sortDeque();
	clock_t	end_deque = clock();
	double	time_deque = double(end_deque - start_deque) / CLOCKS_PER_SEC;

	std::cout << GREEN << "After: " << RESET;
	for (std::size_t i = 0; i < _vector.size(); i++)
		std::cout << _vector[i] << " ";
	std::cout << std::endl;

	std::cout << CYAN << "Time to process a range of " << ac - 1 << " elements with std::vector : " << time_vector << " us" << RESET << std::endl;
	std::cout << CYAN << "Time to process a range of " << ac - 1 << " elements with std::deque : " << time_deque << " us" << RESET << std::endl;
}

PmergeMe::PmergeMe(PmergeMe const &src)
{
	*this = src;
}

PmergeMe &PmergeMe::operator=(PmergeMe const &src)
{
	if (this != &src)
	{
		_vector = src._vector;
		_deque = src._deque;
	}
	return *this;
}

PmergeMe::~PmergeMe(){}

void	PmergeMe::add(int n)
{
	if (n < 0)
		throw NegativeNumber();
	for (std::size_t i = 0; i < _vector.size(); i++)
	{
		if (_vector[i] == n)
			throw DuplicateNumber();
	}
	_vector.push_back(n);
	_deque.push_back(n);
}

const char* PmergeMe::DuplicateNumber::what() const throw()
{
	return RED "Duplicate number" RESET;
}

const char* PmergeMe::NegativeNumber::what() const throw()
{
	return RED "Negative number" RESET;
}

void	PmergeMe::sortVector()
{
	sort(_vector);
}

void	PmergeMe::sortDeque()
{
	sort(_deque);
}

template<typename T>
void PmergeMe::insert(T& container)
{
	typedef typename T::iterator Iterator;

	for (Iterator it = container.begin(); it != container.end(); ++it)
	{
		typename T::value_type currentValue = *it;		// The value to be inserted
		Iterator insertPos = it;						// Position to insert the currentValue

		while (insertPos != container.begin())			// Move elements that are greater than currentValue to the right
		{
			Iterator prev = insertPos;
			--prev;
			
			if (*prev > currentValue)
			{
				*insertPos = *prev;
				insertPos = prev;
			}
			else
			{
				break;
			}
		}
		*insertPos = currentValue;		// Place the currentValue in its correct position
	}
}

template <typename T>
void PmergeMe::sort(T& m)
{
	if (m.size() <= 2)
		return insert(m);

	typename T::iterator mid = m.begin();
	std::advance(mid, m.size() / 2);

	T left(m.begin(), mid);
	T right(mid, m.end());

	sort(left);
	sort(right);

	std::merge(left.begin(), left.end(), right.begin(), right.end(), m.begin());
}