/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismherna <ismherna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 23:38:48 by ismherna          #+#    #+#             */
/*   Updated: 2025/03/20 23:38:49 by ismherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << RED "ERROR: Invalid input: Usage: ./rpn \"[expression]\"" RESET << std::endl;
		return 1;
	}
	try
	{
		RPN rpn(av[1]);
		std::cout << rpn << std::endl;
	}
	catch (std::exception& e)
		std::cerr << RED "ERROR: "   << e.what() RESET << std::endl;
	return 0;
}