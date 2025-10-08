/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhamdan <yhamdan@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-03 11:14:04 by yhamdan           #+#    #+#             */
/*   Updated: 2025-10-03 11:14:04 by yhamdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}
RPN::~RPN() {}
RPN::RPN(const RPN& other) { (void)other; }
RPN& RPN::operator=(const RPN& other) { (void)other; return *this; }

bool RPN::isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int RPN::evaluate(const std::string& exp)
{
    int count = 0;
    for(int i = 0; i < (int)exp.size() ; i++)
    {
        if (exp[i] >= '0' && exp[i] <= '9')
        {
            operands.push(exp[i] - '0');
            count++;
        }
        else if (isOperator(exp[i]))
        {
            if (count < 2)
                throw std::invalid_argument("Invalid RPN expression");
            applyOperator(exp[i]);
            count--;
        }
        else
            throw std::invalid_argument("Invalid RPN expression");
    }
    if (count != 1)
        throw std::invalid_argument("Invalid RPN sequence");
    return (operands.top());
}

void RPN::applyOperator(char op)
{
    int val1 = operands.top();
    operands.pop();
    int val2 = operands.top();
    operands.pop();
    if (op == '+')
        operands.push(val2 + val1);
    if (op == '-')
        operands.push(val2 - val1);
    if (op == '*')
        operands.push(val2 * val1);
    if (op == '/')
        operands.push(val2 / val1);
}