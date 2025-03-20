/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismherna <ismherna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 23:38:56 by ismherna          #+#    #+#             */
/*   Updated: 2025/03/20 23:38:57 by ismherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(std::string str)
{
	int	diff = 0;

	for (size_t i = 0; i < str.size(); i++)
	{
		if (isOperator(str[i]))
		{
			if (_stack.size() < 2)
				throw InvalidExpression();

			int		operand1 = _stack.top();
			_stack.pop();

			int		operand2 = _stack.top();
			_stack.pop();

			if (str[i] == '+')
				_stack.push(operand2 + operand1);
			else if (str[i] == '-')
				_stack.push(operand2 - operand1);
			else if (str[i] == '*')
				_stack.push(operand2 * operand1);
			else if (str[i] == '/')
			{
				if (operand1 == 0)
					throw InvalidExpression();
				_stack.push(operand2 / operand1);
			}

			diff--;
		}
		else if (isNumeric(str[i]))
		{
			_stack.push(str[i] - '0');
			diff++;
		}
		else if (str[i] == ' ')
			continue;
		else
			throw InvalidExpression();
	}
	if (diff != 1)
		throw InvalidExpression();
	_value = _stack.top();
}

RPN::RPN(const RPN& src)
{
	*this = src;
}

RPN& RPN::operator=(const RPN& rhs)
{
	if (this != &rhs)
		this->_stack = rhs._stack;
	return *this;
}

RPN::~RPN()
{}

int RPN::getValue() const
{
	return _value;
}

const char* RPN::InvalidExpression::what() const throw()
{
	return "Invalid expression";
}


bool	isNumeric(char c)
{
	return (c >= '0' && c <= '9');
}

bool	isOperator(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

std::ostream& operator<<(std::ostream& o, const RPN& ref)
{
	o << ref.getValue();
	return o;
}