/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismherna <ismherna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 23:39:43 by ismherna          #+#    #+#             */
/*   Updated: 2025/03/20 23:45:10 by ismherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	int last = -1;
	for (size_t i = 1; i < ac; i++)
	{
		if (atoi(av[i]) > last)
			last = atoi(av[i]);
		else
		{
			printf(RED "ERROR: unordered between %d and %d\n" RESET, last, atoi(av[i]));
			return 1;
		}
	}
	printf("Ordered\n");
}