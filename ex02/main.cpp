/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismherna <ismherna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 23:36:22 by ismherna          #+#    #+#             */
/*   Updated: 2025/03/20 23:39:51 by ismherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	if (ac == 1)
		return 1;

	try
		PmergeMe pm(ac, av);
	catch (std::exception &e)
	{
		std::cerr << RED "ERROR: " RESET << e.what() << std::endl;
		return 1;
	}
}