/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismherna <ismherna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 23:37:40 by ismherna          #+#    #+#             */
/*   Updated: 2025/03/20 23:37:41 by ismherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

/*=================================INCLUDES==================================*/

#include <iostream>
#include <string>
#include <stack>

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

class RPN
{
private:
	std::stack<int> _stack;
	int				_value;

public:
	RPN(std::string expression);
	RPN(const RPN& src);
	RPN& operator=(const RPN& rhs);
	~RPN();
	
	int	getValue() const;

	class InvalidExpression : public std::exception
	{
		virtual const char* what() const throw();
	};
};

/*================================FUNCTIONS=================================*/

bool	isNumeric(char c);
bool	isOperator(char c);
std::ostream& operator<<(std::ostream& os, const RPN& rpn);

#endif