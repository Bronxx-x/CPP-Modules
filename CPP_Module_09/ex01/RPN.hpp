/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhamdan <yhamdan@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-03 11:13:36 by yhamdan           #+#    #+#             */
/*   Updated: 2025-10-03 11:13:36 by yhamdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <stdexcept>

class RPN {
public:
    RPN();
    ~RPN();

    int evaluate(const std::string& exp);

private:
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);
    std::stack<int> operands;
    bool isOperator(char c);
    void applyOperator(char op);
};

#endif