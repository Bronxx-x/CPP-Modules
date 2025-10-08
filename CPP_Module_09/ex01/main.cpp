/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhamdan <yhamdan@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-03 11:13:24 by yhamdan           #+#    #+#             */
/*   Updated: 2025-10-03 11:13:24 by yhamdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

std::string removeSpaces(const std::string &str)
{
    std::string result;
    for (std::string::size_type i = 0; i < str.length(); ++i)
    {
        if (str[i] != ' ')
            result += str[i];
    }
    return result;
}

int main(int argc, char **argv)
{
    (void)argv;
    if (argc != 2)
    {
        std::cerr << "Error: This program takes exactly one argument." << std::endl;
        return 1;
    }
    RPN rpn;
    std::string expression = argv[1];

    int count = 0;
    for (int i = 0; i < (int)expression.size(); i++)
    {
        if ((expression[i] >= '0' && expression[i] <= '9') )
            count++;
        if (count > 1)
        {
            std::cerr << "Error: number should be between 0 - 9"<< std::endl;
            return 1;
        }
        if (expression[i] == ' ' || expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/')
            count = 0;
    }

    expression = removeSpaces(expression);
    try {
        int result = rpn.evaluate(expression);
        std::cout << "Result: " << result << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}