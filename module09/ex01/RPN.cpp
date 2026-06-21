/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telcash <telcash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 22:08:00 by telcash           #+#    #+#             */
/*   Updated: 2026/06/20 22:08:00 by telcash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <cstdlib>
#include <sstream>
#include <stdexcept>

RPN::RPN() {}
RPN::RPN(const RPN &other) { (void)other; }
RPN &RPN::operator=(const RPN &other)
{
    (void)other;
    return *this;
}
RPN::~RPN() {}

bool RPN::_isOperator(const std::string &token)
{
    return token.length() == 1
        && (token[0] == '+' || token[0] == '-' || token[0] == '*'
            || token[0] == '/');
}

bool RPN::_isNumber(const std::string &token)
{
    return token.length() == 1 && token[0] >= '0' && token[0] <= '9';
}

long RPN::_applyOperator(long left, long right, char op)
{
    if (op == '+')
        return left + right;
    if (op == '-')
        return left - right;
    if (op == '*')
        return left * right;
    if (op == '/')
    {
        if (right == 0)
            throw std::runtime_error("Error");
        return left / right;
    }
    throw std::runtime_error("Error");
}

long RPN::evaluate(const std::string &expression)
{
    std::stack<long> values;
    std::istringstream input(expression);
    std::string token;

    while (input >> token)
    {
        if (_isNumber(token))
            values.push(std::atol(token.c_str()));
        else if (_isOperator(token))
        {
            if (values.size() < 2)
                throw std::runtime_error("Error");

            long right = values.top();
            values.pop();
            long left = values.top();
            values.pop();

            values.push(_applyOperator(left, right, token[0]));
        }
        else
            throw std::runtime_error("Error");
    }
    if (values.size() != 1)
        throw std::runtime_error("Error");
    return values.top();
}
