/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousef <yousef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 21:15:48 by yousef            #+#    #+#             */
/*   Updated: 2025/09/15 01:21:08 by yousef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP
#include <string>
#include <iostream>
#include <limits>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cctype>

class ScalarConverter
{
private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &other);
    ScalarConverter &operator=(const ScalarConverter &other);
    ~ScalarConverter();
    static bool isChar(const std::string &str);
    static bool isInt(const std::string &str);
    static bool isFloat(const std::string &str);
    static bool isDouble(const std::string &str);
    static bool isSpecialFloat(const std::string &str);
    static bool isSpecialDouble(const std::string &str);
    static void convertFromChar(const std::string &str);
    static void convertFromInt(const std::string &str);
    static void convertFromFloat(const std::string &str);
    static void convertFromDouble(const std::string &str);
    static void printChar(double value);
    static void printInt(double value);
    static void printFloat(double value);
    static void printDouble(double value);
    static bool isDisplayable(char c);
    static bool isPseudoLiteral(const std::string &str);
public:
    static void convert(const std::string &str);
};

#endif